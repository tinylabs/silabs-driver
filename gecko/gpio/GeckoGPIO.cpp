/**
 *  Driver for EFM32 gecko GPIO
 *
 *  All rights reserved.
 *  Tiny Labs Inc
 *  2019
 */
#include <string.h>

#include <leos/GPIO.h>
#include <leos/reg.h>
#include <leos/clock.h>
#include "leos.h"

#define MAX_PORT  6  // Port A-F
#define MAX_PIN   16 // Up to 16 pins per port (0-15)

typedef struct {
  REG32 CTRL;
  REG32 MODEL;
  REG32 MODEH;
  REG32 DOUT;
  REG32 SET;
  REG32 CLR;
  REG32 TOGGLE;
  REG32 DIN;
  REG32 LOCK;
} port_t;

// Register interface
typedef struct {
  port_t PORT[MAX_PORT]; // Port A-F
  PAD(0xD4, 0x100);
  REG32 INTSELL;
  REG32 INTSELH;
  REG32 INTRISE;
  REG32 INTFALL;
  REG32 IEN;
  REG32 IF;
  REG32 IFC;
  REG32 IFS;
  REG32 ROUTE;
  REG32 INSENSE;
  REG32 LOCK;
} reg_t;

class GeckoGPIO : public GPIO {
 private:
  // Class handler trampoline
  isr_tramp_t tramp[2];
  reg_t *reg;
  clk_node_t clk;
  // Client ISR handlers (1 per pin)
  isr_handler_t isr[MAX_PIN];
  uint8_t irq[2];

  // IRQ handler
  void EvenIRQHandler (void);
  void OddIRQHandler (void);

public:
  GeckoGPIO (int idx, int cnt, va_list ap);
  ~GeckoGPIO () {}

  // Common functions
  int Setup (const char *args);
  void Cleanup (void);

  // iGPIO port interface
  int Set (uint8_t port, uint32_t val);
  uint32_t Get (uint8_t port);
  // iGPIO pin interface
  int Config (uint8_t port, uint8_t pin, const char *cfg);
  int Set (uint8_t port, uint8_t pin, int val);
  int Get (uint8_t port, uint8_t pin);
  int EnableISR (uint8_t port, uint8_t pin, gpio_detect_t type, void (*cb)(void));
  void DisableISR (uint8_t port, uint8_t pin);
};

// Export GPIO object
EXPORT_OBJ (GeckoGPIO, SINGLETON);

GeckoGPIO::GeckoGPIO (int idx, int cnt, va_list ap)
  : GPIO (idx, cnt, ap)
{
  
  // Get address of peripheral
  reg = (reg_t *)va_arg (ap, uint32_t);

  // Get clock node
  clk = (clk_node_t)va_arg (ap, uint32_t);
}

int GeckoGPIO::Setup (const char *args)
{
  int rv;
  
  // Enable clocks necessary
  leos_clock_set (clk, 1);

  // Create trampoline - divert all GPIO IRQs to fn
  ISR_INIT_TRAMP (&tramp[0], &GeckoGPIO::EvenIRQHandler);
  ISR_INIT_TRAMP (&tramp[1], &GeckoGPIO::OddIRQHandler);

  // Get IRQs GPIO_EVEN/GPIO_ODD
  rv = leos_irq_byname ("GPIO_EVEN", &irq[0]);
  rv |= leos_irq_byname ("GPIO_ODD", &irq[1]);
  if (rv)
    return -1;
  
  // Install ISRs point to trampoline function
  leos_irq_isr (irq[0], &tramp[0]);
  leos_irq_isr (irq[1], &tramp[1]);
  
  // Success
  return 0;
}

void GeckoGPIO::Cleanup (void)
{  
  // Uninstall IRQ handlers
  leos_irq_isr (irq[0], NULL);
  leos_irq_isr (irq[1], NULL);
   
  // Disable clock
  leos_clock_set (clk, 0);
}

/* Portwise functions */
int GeckoGPIO::Set (uint8_t port, uint32_t val)
{
  // Check bounds
  if (port >= MAX_PORT)
    return -1;

  // Set value
  reg->PORT[port].DOUT = val & 0xffff;
  return 0;
}

uint32_t GeckoGPIO::Get (uint8_t port)
{
  // Check bounds
  if (port >= MAX_PORT)
    return -1;

  // Return value
  return reg->PORT[port].DIN;
}

/* Pinwise functions */
int GeckoGPIO::Config (uint8_t port, uint8_t pin, const char *cfg)
{
  uint8_t mode, dout = 0;

  // Check bounds
  if ((port >= MAX_PORT) || (pin >= MAX_PIN))
    return -1;

  // Switch on config
  switch (*cfg) {

    /* Tristate/disable - also used for analog input */
    case 'X':
      mode = 0;
      break;
    case 'I':
    {
      switch (cfg[1])
      {
        /* Normal input */
        case '\0':
          mode = 1;
          break;
        /* Input pull-up */
        case '^':
          mode = 2;
          dout = 1;
          break;
        /* Input pull-down */
        case 'v':
          mode = 2;
          break;
        default:
          return -1;
      }
      break;
    }
    case 'O':
    {
      switch (cfg[1])
      {
        /* Normal output */
        case '\0':
          mode = 5;
          break;
        /* Open source */
        case 'S':
          /* Enable pull-down if specified */
          if (cfg[2] == 'v')
            mode = 7;
          else
            mode = 6;
          break;
        /* Open drain */
        case 'D':
          /* Enable pull-up if specified */
          if (cfg[2] == '^')
            mode = 14;
          else
            mode = 12;
          break;
      }
      break;
    }
    /* Set current 0-3 - There is only per port control on gecko */
    case 'C':
    {
      switch (cfg[1])
      {
        case '\0':
        case '0': /* 0.1mA */
          reg->PORT[port].CTRL = 1;
          return 0;
        case '1': /* 1mA */
          reg->PORT[port].CTRL = 3;
          return 0;
        default:
        case '2': /* 6mA */
          reg->PORT[port].CTRL = 0;
          return 0;
        case '3': /* 20mA */
          reg->PORT[port].CTRL = 2;
          return 0;
      }
    }
    /* Set slew rate - Not supported on target */
    case 'S':
      return 0;
    /* Unknown mode */
    default:
      return -1;
  }

  // Set mode 0-7
  if (pin < 8) {
    reg->PORT[port].MODEL &= ~(0xf << (pin * 4));
    reg->PORT[port].MODEL |= (mode << (pin * 4));
  }
  // Set mode 8-15
  else {
    pin -= 8;
    reg->PORT[port].MODEH &= ~(0xf << (pin * 4));
    reg->PORT[port].MODEH |= (mode << (pin * 4));
  }

  /* Set/clr dout if specified */
  if (dout)
    reg->PORT[port].SET = (1 << pin);
  else
    reg->PORT[port].CLR = (1 << pin);

  /* Success */
  return 0;
}

int GeckoGPIO::Set (uint8_t port, uint8_t pin, int val)
{
  // Check bounds
  if ((port >= MAX_PORT) || (pin >= MAX_PIN))
    return -1;

  // Set bit
  if (val)
    reg->PORT[port].SET = (1 << pin);
  else
    reg->PORT[port].CLR = (1 << pin);
  return 0;
}

int GeckoGPIO::Get (uint8_t port, uint8_t pin)
{
  // Check bounds
  if ((port >= MAX_PORT) || (pin >= MAX_PIN))
    return -1;

  // Return pin state
  return reg->PORT[port].DIN & (1 << pin) ? 1 : 0;
}

// Register ISR
int GeckoGPIO::EnableISR (uint8_t port, uint8_t pin, gpio_detect_t type, void (*cb)(void))
{
  // Check bounds
  if ((port >= MAX_PORT) || (pin >= MAX_PIN))
    return -1;

  // Setup pin/port
  if (pin < 8)
    reg->INTSELL = (reg->INTSELL & ~(7 << (pin * 4))) | (port << (pin * 4));
  else
    reg->INTSELH = (reg->INTSELH & ~(7 << ((pin - 8) * 4))) | (port << ((pin - 8) * 4));
  
  // Set detection type
  if ((type == GPIO_EDGE_RISING) ||
      (type == GPIO_EDGE_BOTH))
    reg->INTRISE = (1 << pin);
  if ((type == GPIO_EDGE_FALLING) ||
      (type == GPIO_EDGE_BOTH))
    reg->INTFALL = (1 << pin);
  
  // Install callback
  isr[pin] = cb;

  // Enable interrupt
  reg->IEN = (1 << pin);

  // Success
  return 0;
}

void GeckoGPIO::DisableISR (uint8_t port, uint8_t pin)
{
  // Check bounds
  if ((port >= MAX_PORT) || (pin >= MAX_PIN))
    return;

  // Disable interrupt
  reg->IEN &= ~(1 << pin);
  
  // Remove handler
  isr[pin] = NULL;
}

/* IRQ handlers */
void GeckoGPIO::EvenIRQHandler (void)
{
  // Get ISR flags
  uint32_t flags = reg->IF & 0x5555; 

  // Figure out which IRQ fired
  while (flags) {

    // Get pin
    uint8_t pin = 31 - __builtin_clz (flags);
    
    // Dispatch handler
    if (isr[pin])
      isr[pin]();
  
    // Clear IRQ
    reg->IFC = pin;

    // Sample flags
    flags = reg->IF;
  }
}

void GeckoGPIO::OddIRQHandler (void)
{
  // Get ISR flags
  uint32_t flags = reg->IF & 0xAAAA; 

  // Figure out which IRQ fired
  while (flags) {

    // Get pin
    uint8_t pin = 31 - __builtin_clz (flags);
    
    // Dispatch handler
    if (isr[pin])
      isr[pin]();
  
    // Clear IRQ
    reg->IFC = pin;

    // Sample flags
    flags = reg->IF;
  }
}
