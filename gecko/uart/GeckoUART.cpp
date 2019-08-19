/**
 *  Driver for CMSDK APB UART - Implemented in MPS2 FPGA development boards.
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
  REG32 DATA;
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
  clk = (clk_node_t)va_arg (ap, clk_node_t);
}

int GeckoUART::Setup (const char *args)
{
  uint32_t freq;
  
  // Enable clocks necessary
  clock_set (clk, 1);

  // Get frequency
  freq = clock_get_freq (clk);
  
  // Probe to make sure we have the correct peripheral

  // Setup UART
  return 0;
}

void GeckoUART::Cleanup (void)
{
  // Disable clock
  clock_set (clk, 0);
}

int GeckoUART::Read (void *buf, int len)
{
  return 0;
}

int GeckoUART::Write (const void *buf, int len)
{
  return len;
}

