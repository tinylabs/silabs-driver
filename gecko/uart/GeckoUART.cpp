/**
 *  Driver for CMSDK APB UART - Implemented in MPS2 FPGA development boards.
 *
 *  All rights reserved.
 *  Tiny Labs Inc
 *  2019
 */
#include <string.h>

#include <leos/iChar.h>
#include "leos/reg.h"

// Register interface
typedef struct {
  REG32 DATA;
  REG32 STATE;
  REG32 CTRL;
  union {
    REG32 INTSTAT;
    REG32 INTCLR;  // W1C
  };
  REG32 BAUDDIV;
  PAD (0x3F0-1);
  REG32 PID[8];  // ID registers
  REG32 CID[4];
} reg_t;

// Peripheral ID
const char periph_id[] = { 0x04, 0x00, 0x00, 0x00,
                           0x18, 0xb8, 0x1b, 0x00,
                           0x0d, 0xf0, 0x05, 0xb1};

class GeckoUART : public iChar {
 private:
  reg_t *reg;
  char *clk;
  
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
  clk = (char *)va_arg (ap, char *);

  // Get clock nodes
}

int GeckoUART::Setup (const char *args)
{
  // Enable any clocks necessary
  
  // Probe to make sure we have the correct peripheral

  // Setup UART
  reg->BAUDDIV = 217; 
  reg->STATE = 0xC;
  reg->CTRL = 3 | (1 << 6);
  return 0;
}

void GeckoUART::Cleanup (void)
{
  // Disable clocks
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
    while (reg->STATE & 1)
      ;
    reg->DATA = cbuf[i];
  }
  return len;
}

