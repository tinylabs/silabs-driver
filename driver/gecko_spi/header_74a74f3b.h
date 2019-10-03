/* DO NOT EDIT: This file is autogenerated. */
#ifdef HEADER_74A74F3B
  #error "Only include from driver CPP!"
#define HEADER_74A74F3B

typedef enum {
  OVS_X16            = 0, /* Regular UART mode with 16X oversampling in asynchronous mode */
  OVS_X8             = 1, /* Double speed with 8X oversampling in asynchronous mode */
  OVS_X6             = 2, /* 6X oversampling in asynchronous mode */
  OVS_X4             = 3, /* Quadruple speed with 4X oversampling in asynchronous mode */
} OVS_enum;

typedef enum {
  TXDELAY_NONE       = 0, /* Frames are transmitted immediately */
  TXDELAY_SINGLE     = 1, /* Transmission of new frames are delayed by a single baud period */
  TXDELAY_DOUBLE     = 2, /* Transmission of new frames are delayed by two baud periods */
  TXDELAY_TRIPLE     = 3, /* Transmission of new frames are delayed by three baud periods */
} TXDELAY_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 SYNC         : 1; /* RW: USART Synchronous Mode */
    REG32 LOOPBK       : 1; /* RW: Loopback Enable */
    REG32 CCEN         : 1; /* RW: Collision Check Enable */
    REG32 MPM          : 1; /* RW: Multi-Processor Mode */
    REG32 MPAB         : 1; /* RW: Multi-Processor Address-Bit */
    REG32 OVS          : 2; /* RW: Oversampling */
    REG32 PAD7         : 1;
    REG32 CLKPOL       : 1; /* RW: Clock Polarity */
    REG32 CLKPHA       : 1; /* RW: Clock Edge For Setup/Sample */
    REG32 MSBF         : 1; /* RW: Most Significant Bit First */
    REG32 CSMA         : 1; /* RW: Action On Slave-Select In Master Mode */
    REG32 TXBIL        : 1; /* RW: TX Buffer Interrupt Level */
    REG32 RXINV        : 1; /* RW: Receiver Input Invert */
    REG32 TXINV        : 1; /* RW: Transmitter output Invert */
    REG32 CSINV        : 1; /* RW: Chip Select Invert */
    REG32 AUTOCS       : 1; /* RW: Automatic Chip Select */
    REG32 AUTOTRI      : 1; /* RW: Automatic TX Tristate */
    REG32 SCMODE       : 1; /* RW: SmartCard Mode */
    REG32 SCRETRANS    : 1; /* RW: SmartCard Retransmit */
    REG32 SKIPPERRF    : 1; /* RW: Skip Parity Error Frames */
    REG32 BIT8DV       : 1; /* RW: Bit 8 Default Value */
    REG32 ERRSDMA      : 1; /* RW: Halt DMA On Error */
    REG32 ERRSRX       : 1; /* RW: Disable RX On Error */
    REG32 ERRSTX       : 1; /* RW: Disable TX On Error */
    REG32 PAD25        : 1;
    REG32 TXDELAY      : 2; /* RW: TX Delay Transmission */
    REG32 BYTESWAP     : 1; /* RW: Byteswap In Double Accesses */
  };
} _0000; /* CTRL */

typedef enum {
  DATABITS_FOUR      = 1, /* Each frame contains 4 data bits */
  DATABITS_FIVE      = 2, /* Each frame contains 5 data bits */
  DATABITS_SIX       = 3, /* Each frame contains 6 data bits */
  DATABITS_SEVEN     = 4, /* Each frame contains 7 data bits */
  DATABITS_EIGHT     = 5, /* Each frame contains 8 data bits */
  DATABITS_NINE      = 6, /* Each frame contains 9 data bits */
  DATABITS_TEN       = 7, /* Each frame contains 10 data bits */
  DATABITS_ELEVEN    = 8, /* Each frame contains 11 data bits */
  DATABITS_TWELVE    = 9, /* Each frame contains 12 data bits */
  DATABITS_THIRTEEN  = 10, /* Each frame contains 13 data bits */
  DATABITS_FOURTEEN  = 11, /* Each frame contains 14 data bits */
  DATABITS_FIFTEEN   = 12, /* Each frame contains 15 data bits */
  DATABITS_SIXTEEN   = 13, /* Each frame contains 16 data bits */
} DATABITS_enum;

typedef enum {
  PARITY_NONE        = 0, /* Parity bits are not used */
  PARITY_EVEN        = 2, /* Even parity are used. Parity bits are automatically generated and checked by hardware. */
  PARITY_ODD         = 3, /* Odd parity is used. Parity bits are automatically generated and checked by hardware. */
} PARITY_enum;

typedef enum {
  STOPBITS_HALF      = 0, /* The transmitter generates a half stop bit. Stop-bits are not verified by receiver */
  STOPBITS_ONE       = 1, /* One stop bit is generated and verified */
  STOPBITS_ONEANDAHALF = 2, /* The transmitter generates one and a half stop bit. The receiver verifies the first stop bit */
  STOPBITS_TWO       = 3, /* The transmitter generates two stop bits. The receiver checks the first stop-bit only */
} STOPBITS_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 DATABITS     : 4; /* RW: Data-Bit Mode */
    REG32 PAD4         : 4;
    REG32 PARITY       : 2; /* RW: Parity-Bit Mode */
    REG32 PAD10        : 2;
    REG32 STOPBITS     : 2; /* RW: Stop-Bit Mode */
  };
} _0004; /* FRAME */

typedef enum {
  TSEL_PRSCH0        = 0, /* PRS Channel 0 selected */
  TSEL_PRSCH1        = 1, /* PRS Channel 1 selected */
  TSEL_PRSCH2        = 2, /* PRS Channel 2 selected */
  TSEL_PRSCH3        = 3, /* PRS Channel 3 selected */
  TSEL_PRSCH4        = 4, /* PRS Channel 4 selected */
  TSEL_PRSCH5        = 5, /* PRS Channel 5 selected */
  TSEL_PRSCH6        = 6, /* PRS Channel 6 selected */
  TSEL_PRSCH7        = 7, /* PRS Channel 7 selected */
} TSEL_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 TSEL         : 3; /* RW: Trigger PRS Channel Select */
    REG32 PAD3         : 1;
    REG32 RXTEN        : 1; /* RW: Receive Trigger Enable */
    REG32 TXTEN        : 1; /* RW: Transmit Trigger Enable */
  };
} _0008; /* TRIGCTRL */

typedef struct {
  union {
    REG32 REG;
    REG32 RXEN         : 1; /* WO: Receiver Enable */
    REG32 RXDIS        : 1; /* WO: Receiver Disable */
    REG32 TXEN         : 1; /* WO: Transmitter Enable */
    REG32 TXDIS        : 1; /* WO: Transmitter Disable */
    REG32 MASTEREN     : 1; /* WO: Master Enable */
    REG32 MASTERDIS    : 1; /* WO: Master Disable */
    REG32 RXBLOCKEN    : 1; /* WO: Receiver Block Enable */
    REG32 RXBLOCKDIS   : 1; /* WO: Receiver Block Disable */
    REG32 TXTRIEN      : 1; /* WO: Transmitter Tristate Enable */
    REG32 TXTRIDIS     : 1; /* WO: Transmitter Tristate Disable */
    REG32 CLEARTX      : 1; /* WO: Clear TX */
    REG32 CLEARRX      : 1; /* WO: Clear RX */
  };
} _000C; /* CMD */

typedef struct {
  union {
    REG32 REG;
    REG32 RXENS        : 1; /* RO: Receiver Enable Status */
    REG32 TXENS        : 1; /* RO: Transmitter Enable Status */
    REG32 MASTER       : 1; /* RO: SPI Master Mode */
    REG32 RXBLOCK      : 1; /* RO: Block Incoming Data */
    REG32 TXTRI        : 1; /* RO: Transmitter Tristated */
    REG32 TXC          : 1; /* RO: TX Complete */
    REG32 TXBL         : 1; /* RO: TX Buffer Level */
    REG32 RXDATAV      : 1; /* RO: RX Data Valid */
    REG32 RXFULL       : 1; /* RO: RX FIFO Full */
  };
} _0010; /* STATUS */

typedef struct {
  union {
    REG32 REG;
    REG32 PAD0         : 6;
    REG32 DIV          : 15; /* RW: Fractional Clock Divider */
  };
} _0014; /* CLKDIV */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATA       : 9; /* RO: RX Data */
    REG32 PAD9         : 5;
    REG32 PERR         : 1; /* RO: Data Parity Error */
    REG32 FERR         : 1; /* RO: Data Framing Error */
  };
} _0018; /* RXDATAX */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATA       : 8; /* RO: RX Data */
  };
} _001C; /* RXDATA */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATA0      : 9; /* RO: RX Data 0 */
    REG32 PAD9         : 5;
    REG32 PERR0        : 1; /* RO: Data Parity Error 0 */
    REG32 FERR0        : 1; /* RO: Data Framing Error 0 */
    REG32 RXDATA1      : 9; /* RO: RX Data 1 */
    REG32 PAD25        : 5;
    REG32 PERR1        : 1; /* RO: Data Parity Error 1 */
    REG32 FERR1        : 1; /* RO: Data Framing Error 1 */
  };
} _0020; /* RXDOUBLEX */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATA0      : 8; /* RO: RX Data 0 */
    REG32 RXDATA1      : 8; /* RO: RX Data 1 */
  };
} _0024; /* RXDOUBLE */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATAP      : 9; /* RO: RX Data Peek */
    REG32 PAD9         : 5;
    REG32 PERRP        : 1; /* RO: Data Parity Error Peek */
    REG32 FERRP        : 1; /* RO: Data Framing Error Peek */
  };
} _0028; /* RXDATAXP */

typedef struct {
  union {
    REG32 REG;
    REG32 RXDATAP0     : 9; /* RO: RX Data 0 Peek */
    REG32 PAD9         : 5;
    REG32 PERRP0       : 1; /* RO: Data Parity Error 0 Peek */
    REG32 FERRP0       : 1; /* RO: Data Framing Error 0 Peek */
    REG32 RXDATAP1     : 9; /* RO: RX Data 1 Peek */
    REG32 PAD25        : 5;
    REG32 PERRP1       : 1; /* RO: Data Parity Error 1 Peek */
    REG32 FERRP1       : 1; /* RO: Data Framing Error 1 Peek */
  };
} _002C; /* RXDOUBLEXP */

typedef struct {
  union {
    REG32 REG;
    REG32 TXDATAX      : 9; /* WO: TX Data */
    REG32 PAD9         : 2;
    REG32 UBRXAT       : 1; /* WO: Unblock RX After Transmission */
    REG32 TXTRIAT      : 1; /* WO: Set TXTRI After Transmission */
    REG32 TXBREAK      : 1; /* WO: Transmit Data As Break */
    REG32 TXDISAT      : 1; /* WO: Clear TXEN After Transmission */
    REG32 RXENAT       : 1; /* WO: Enable RX After Transmission */
  };
} _0030; /* TXDATAX */

typedef struct {
  union {
    REG32 REG;
    REG32 TXDATA       : 8; /* WO: TX Data */
  };
} _0034; /* TXDATA */

typedef struct {
  union {
    REG32 REG;
    REG32 TXDATA0      : 9; /* WO: TX Data */
    REG32 PAD9         : 2;
    REG32 UBRXAT0      : 1; /* WO: Unblock RX After Transmission */
    REG32 TXTRIAT0     : 1; /* WO: Set TXTRI After Transmission */
    REG32 TXBREAK0     : 1; /* WO: Transmit Data As Break */
    REG32 TXDISAT0     : 1; /* WO: Clear TXEN After Transmission */
    REG32 RXENAT0      : 1; /* WO: Enable RX After Transmission */
    REG32 TXDATA1      : 9; /* WO: TX Data */
    REG32 PAD25        : 2;
    REG32 UBRXAT1      : 1; /* WO: Unblock RX After Transmission */
    REG32 TXTRIAT1     : 1; /* WO: Set TXTRI After Transmission */
    REG32 TXBREAK1     : 1; /* WO: Transmit Data As Break */
    REG32 TXDISAT1     : 1; /* WO: Clear TXEN After Transmission */
    REG32 RXENAT1      : 1; /* WO: Enable RX After Transmission */
  };
} _0038; /* TXDOUBLEX */

typedef struct {
  union {
    REG32 REG;
    REG32 TXDATA0      : 8; /* WO: TX Data */
    REG32 TXDATA1      : 8; /* WO: TX Data */
  };
} _003C; /* TXDOUBLE */

typedef struct {
  union {
    REG32 REG;
    REG32 TXC          : 1; /* RO: TX Complete Interrupt Flag */
    REG32 TXBL         : 1; /* RO: TX Buffer Level Interrupt Flag */
    REG32 RXDATAV      : 1; /* RO: RX Data Valid Interrupt Flag */
    REG32 RXFULL       : 1; /* RO: RX Buffer Full Interrupt Flag */
    REG32 RXOF         : 1; /* RO: RX Overflow Interrupt Flag */
    REG32 RXUF         : 1; /* RO: RX Underflow Interrupt Flag */
    REG32 TXOF         : 1; /* RO: TX Overflow Interrupt Flag */
    REG32 TXUF         : 1; /* RO: TX Underflow Interrupt Flag */
    REG32 PERR         : 1; /* RO: Parity Error Interrupt Flag */
    REG32 FERR         : 1; /* RO: Framing Error Interrupt Flag */
    REG32 MPAF         : 1; /* RO: Multi-Processor Address Frame Interrupt Flag */
    REG32 SSM          : 1; /* RO: Slave-Select In Master Mode Interrupt Flag */
    REG32 CCF          : 1; /* RO: Collision Check Fail Interrupt Flag */
  };
} _0040; /* IF */

typedef struct {
  union {
    REG32 REG;
    REG32 TXC          : 1; /* WO: Set TX Complete Interrupt Flag */
    REG32 PAD1         : 2;
    REG32 RXFULL       : 1; /* WO: Set RX Buffer Full Interrupt Flag */
    REG32 RXOF         : 1; /* WO: Set RX Overflow Interrupt Flag */
    REG32 RXUF         : 1; /* WO: Set RX Underflow Interrupt Flag */
    REG32 TXOF         : 1; /* WO: Set TX Overflow Interrupt Flag */
    REG32 TXUF         : 1; /* WO: Set TX Underflow Interrupt Flag */
    REG32 PERR         : 1; /* WO: Set Parity Error Interrupt Flag */
    REG32 FERR         : 1; /* WO: Set Framing Error Interrupt Flag */
    REG32 MPAF         : 1; /* WO: Set Multi-Processor Address Frame Interrupt Flag */
    REG32 SSM          : 1; /* WO: Set Slave-Select in Master mode Interrupt Flag */
    REG32 CCF          : 1; /* WO: Set Collision Check Fail Interrupt Flag */
  };
} _0044; /* IFS */

typedef struct {
  union {
    REG32 REG;
    REG32 TXC          : 1; /* WO: Clear TX Complete Interrupt Flag */
    REG32 PAD1         : 2;
    REG32 RXFULL       : 1; /* WO: Clear RX Buffer Full Interrupt Flag */
    REG32 RXOF         : 1; /* WO: Clear RX Overflow Interrupt Flag */
    REG32 RXUF         : 1; /* WO: Clear RX Underflow Interrupt Flag */
    REG32 TXOF         : 1; /* WO: Clear TX Overflow Interrupt Flag */
    REG32 TXUF         : 1; /* WO: Clear TX Underflow Interrupt Flag */
    REG32 PERR         : 1; /* WO: Clear Parity Error Interrupt Flag */
    REG32 FERR         : 1; /* WO: Clear Framing Error Interrupt Flag */
    REG32 MPAF         : 1; /* WO: Clear Multi-Processor Address Frame Interrupt Flag */
    REG32 SSM          : 1; /* WO: Clear Slave-Select In Master Mode Interrupt Flag */
    REG32 CCF          : 1; /* WO: Clear Collision Check Fail Interrupt Flag */
  };
} _0048; /* IFC */

typedef struct {
  union {
    REG32 REG;
    REG32 TXC          : 1; /* RW: TX Complete Interrupt Enable */
    REG32 TXBL         : 1; /* RW: TX Buffer Level Interrupt Enable */
    REG32 RXDATAV      : 1; /* RW: RX Data Valid Interrupt Enable */
    REG32 RXFULL       : 1; /* RW: RX Buffer Full Interrupt Enable */
    REG32 RXOF         : 1; /* RW: RX Overflow Interrupt Enable */
    REG32 RXUF         : 1; /* RW: RX Underflow Interrupt Enable */
    REG32 TXOF         : 1; /* RW: TX Overflow Interrupt Enable */
    REG32 TXUF         : 1; /* RW: TX Underflow Interrupt Enable */
    REG32 PERR         : 1; /* RW: Parity Error Interrupt Enable */
    REG32 FERR         : 1; /* RW: Framing Error Interrupt Enable */
    REG32 MPAF         : 1; /* RW: Multi-Processor Address Frame Interrupt Enable */
    REG32 SSM          : 1; /* RW: Slave-Select In Master Mode Interrupt Enable */
    REG32 CCF          : 1; /* RW: Collision Check Fail Interrupt Enable */
  };
} _004C; /* IEN */

typedef enum {
  IRPW_ONE           = 0, /* IrDA pulse width is 1/16 for OVS=0 and 1/8 for OVS=1 */
  IRPW_TWO           = 1, /* IrDA pulse width is 2/16 for OVS=0 and 2/8 for OVS=1 */
  IRPW_THREE         = 2, /* IrDA pulse width is 3/16 for OVS=0 and 3/8 for OVS=1 */
  IRPW_FOUR          = 3, /* IrDA pulse width is 4/16 for OVS=0 and 4/8 for OVS=1 */
} IRPW_enum;

typedef enum {
  IRPRSSEL_PRSCH0    = 0, /* PRS Channel 0 selected */
  IRPRSSEL_PRSCH1    = 1, /* PRS Channel 1 selected */
  IRPRSSEL_PRSCH2    = 2, /* PRS Channel 2 selected */
  IRPRSSEL_PRSCH3    = 3, /* PRS Channel 3 selected */
  IRPRSSEL_PRSCH4    = 4, /* PRS Channel 4 selected */
  IRPRSSEL_PRSCH5    = 5, /* PRS Channel 5 selected */
  IRPRSSEL_PRSCH6    = 6, /* PRS Channel 6 selected */
  IRPRSSEL_PRSCH7    = 7, /* PRS Channel 7 selected */
} IRPRSSEL_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 IREN         : 1; /* RW: Enable IrDA Module */
    REG32 IRPW         : 2; /* RW: IrDA TX Pulse Width */
    REG32 IRFILT       : 1; /* RW: IrDA RX Filter */
    REG32 IRPRSSEL     : 3; /* RW: IrDA PRS Channel Select */
    REG32 IRPRSEN      : 1; /* RW: IrDA PRS Channel Enable */
  };
} _0050; /* IRCTRL */

typedef enum {
  LOCATION_LOC0      = 0, /* Location 0 */
  LOCATION_LOC1      = 1, /* Location 1 */
  LOCATION_LOC2      = 2, /* Location 2 */
  LOCATION_LOC3      = 3, /* Location 3 */
} LOCATION_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 RXPEN        : 1; /* RW: RX Pin Enable */
    REG32 TXPEN        : 1; /* RW: TX Pin Enable */
    REG32 CSPEN        : 1; /* RW: CS Pin Enable */
    REG32 CLKPEN       : 1; /* RW: CLK Pin Enable */
    REG32 PAD4         : 4;
    REG32 LOCATION     : 2; /* RW: I/O Location */
  };
} _0054; /* ROUTE */


// Top-level register defs
typedef struct {
  _0000 CTRL;          /* RW: Control Register */
  _0004 FRAME;         /* RW: USART Frame Format Register */
  _0008 TRIGCTRL;      /* RW: USART Trigger Control register */
  _000C CMD;           /* WO: Command Register */
  _0010 STATUS;        /* RO: USART Status Register */
  _0014 CLKDIV;        /* RW: Clock Control Register */
  _0018 RXDATAX;       /* RO: RX Buffer Data Extended Register */
  _001C RXDATA;        /* RO: RX Buffer Data Register */
  _0020 RXDOUBLEX;     /* RO: RX Buffer Double Data Extended Register */
  _0024 RXDOUBLE;      /* RO: RX FIFO Double Data Register */
  _0028 RXDATAXP;      /* RO: RX Buffer Data Extended Peek Register */
  _002C RXDOUBLEXP;    /* RO: RX Buffer Double Data Extended Peek Register */
  _0030 TXDATAX;       /* WO: TX Buffer Data Extended Register */
  _0034 TXDATA;        /* WO: TX Buffer Data Register */
  _0038 TXDOUBLEX;     /* WO: TX Buffer Double Data Extended Register */
  _003C TXDOUBLE;      /* WO: TX Buffer Double Data Register */
  _0040 IF;            /* RO: Interrupt Flag Register */
  _0044 IFS;           /* WO: Interrupt Flag Set Register */
  _0048 IFC;           /* WO: Interrupt Flag Clear Register */
  _004C IEN;           /* RW: Interrupt Enable Register */
  _0050 IRCTRL;        /* RW: IrDA Control Register */
  _0054 ROUTE;         /* RW: I/O Routing Register */
} reg_t;
#define P74A74F3B_FP 0x9cbbeddc
#define P74A74F3B_SZ 1024