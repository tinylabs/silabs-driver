/**
 *  Driver for EFM32 gecko UART
 *
 *  All rights reserved.
 *  Tiny Labs Inc
 *  2019
 */
#include <string.h>

#include <leos/iChar.h>
#include <leos/reg.h>
#include <leos/clock.h>
#include "leos.h"

// Register interface
typedef struct {
  REG32 CTRL;
  REG32 FRAME;
  REG32 TRIGCTRL;
  REG32 CMD;
  REG32 STATUS;
  REG32 CLKDIV;
  REG32 RXDATAX;
  REG32 RXDATA;
  REG32 RXDOUBLEX;
  REG32 RXDOUBLE;
  REG32 RXDATAXP;
  REG32 RXDOUBLEXP;
  REG32 TXDATAX;
  REG32 TXDATA;
  REG32 TXDOUBLEX;
  REG32 TXDOUBLE;
  REG32 IF;
  REG32 IFS;
  REG32 IFC;
  REG32 IEN;
  REG32 IRCTRL;
  REG32 ROUTE;
} reg_t;

class GeckoUART : public iChar {
 private:
  reg_t *reg;
  clk_node_t clk;
  
 public:
  GeckoUART (int idx, int cnt, va_list ap);
  ~GeckoUART () {}

  // Common functions
  int Setup (const char *args);
  void Cleanup (void);

  // iCharDev interface
  int Read (void *buf, int len);
  int Write (const void *buf, int len);
};

EXPORT_OBJ (GeckoUART, NORMAL);

GeckoUART::GeckoUART (int idx, int cnt, va_list ap)
  : iChar (idx)
{
  
  // Get address of peripheral
  reg = (reg_t *)va_arg (ap, uint32_t);

  // Get clock node
  clk = (clk_node_t)va_arg (ap, uint32_t);
}

int GeckoUART::Setup (const char *args)
{
  int rv;
  uint32_t freq, baud;
  char *mode;
  
  // Enable clocks necessary
  leos_clock_set (clk, 1);

  // Get frequency
  freq = leos_clock_freq (clk);
  
  // Get baud rate
  rv = leos_parse_uint (args, "baud=", &baud);
  if (rv)
    return -1;

  // Get mode
  rv = leos_parse_str (args, "mode=", &mode);
  if (rv)
    return -1;
  
  // Free string
  leos_free (mode);

  // Configure UART
  reg->CMD = (3 << 10);

  // Enable 4x oversampling (vs 16x)
  reg->CTRL |= (3 << 5);

  // Set baud rate
  if (freq <= 16000000)
    reg->CLKDIV = ((256 * freq) / (4 * baud)) - 256;
  else
    reg->CLKDIV = 256 * ((freq / (4 * baud)) - 1);

  // Enable pins
  reg->ROUTE = 3;

  // Enable transmit
  reg->CMD = 4;
  
  // Install ISRs

  // Setup UART
  return 0;
}

void GeckoUART::Cleanup (void)
{
  // Disable clock
  leos_clock_set (clk, 0);
}

int GeckoUART::Read (void *buf, int len)
{
  return 0;
}

int GeckoUART::Write (const void *buf, int len)
{
  int i;
  uint8_t *cbuf = (uint8_t *)buf;
  for (i = 0; i < len; i++) {
    reg->TXDATAX = cbuf[i];
    while ((reg->STATUS & (1 << 5)) == 0)
      ;
  }
  return len;
}

// ISRs
