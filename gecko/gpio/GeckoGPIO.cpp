/**
 *  Driver for EFM32 gecko GPIO
 *
 *  All rights reserved.
 *  Tiny Labs Inc
 *  2019
 */
#include <string.h>

#include <leos/iGPIO.h>
#include <leos/reg.h>
#include <leos/clock.h>
#include "leos.h"

// Register interface
typedef struct {
  REG32 CTRL;
} reg_t;

class GeckoGPIO : public iGPIO {
 private:
  reg_t *reg;
  clk_node_t clk;
  
 public:
  GeckoGPIO (int idx, int cnt, va_list ap);
  ~GeckoGPIO () {}

  // Common functions
  int Setup (const char *args);
  void Cleanup (void);

  // iGPIO interface
  int Set (char port, int val);
  uint32_t Get (char port);
  int Config (const char *pin, const char *cfg);
  int Set (const char *pin, int val);
  uint32_t Get (const char *pin);
};

EXPORT_OBJ (GeckoGPIO, NORMAL);

GeckoGPIO::GeckoGPIO (int idx, int cnt, va_list ap)
  : iGPIO (idx)
{
  
  // Get address of peripheral
  reg = (reg_t *)va_arg (ap, uint32_t);

  // Get clock node
  clk = (clk_node_t)va_arg (ap, uint32_t);
}

int GeckoGPIO::Setup (const char *args)
{
  int rv;
  uint32_t freq, baud;
  char *mode;
  
  // Enable clocks necessary
  leos_clock_set (clk, 1);

  // Success
  return 0;
}

void GeckoGPIO::Cleanup (void)
{
  // Disable clock
  leos_clock_set (clk, 0);
}

int GeckoGPIO::Set (char port, int val)
{
  return 0;
}

uint32_t GeckoGPIO::Get (char port)
{
  return 0;
}

int GeckoGPIO::Config (const char *pin, const char *cfg)
{
  return 0;
}


int GeckoGPIO::Set (const char *pin, int val)
{
  return 0;
}

uint32_t GeckoGPIO::Get (const char *pin)
{
  return 0;
}

// ISRs
