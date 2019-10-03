/* DO NOT EDIT: This file is autogenerated. */
#ifdef HEADER_F19D3F5F
  #error "Only include from driver CPP!"
#define HEADER_F19D3F5F

typedef enum {
  WARMUPMODE_NORMAL  = 0, /* ADC is shut down after each conversion */
  WARMUPMODE_FASTBG  = 1, /* Bandgap references do not need warm up, but have reduced accuracy. */
  WARMUPMODE_KEEPSCANREFWARM = 2, /* Reference selected for scan mode is kept warm. */
  WARMUPMODE_KEEPADCWARM = 3, /* ADC is kept warmed up and scan reference is kept warm */
} WARMUPMODE_enum;

typedef enum {
  LPFMODE_BYPASS     = 0, /* No filter or decoupling capacitor */
  LPFMODE_DECAP      = 1, /* On chip decoupling capacitor selected */
  LPFMODE_RCFILT     = 2, /* On chip RC filter selected */
} LPFMODE_enum;

typedef enum {
  PRESC_NODIVISION   = 0, /*  */
} PRESC_enum;

typedef enum {
  OVSRSEL_X2         = 0, /* 2 samples for each conversion result */
  OVSRSEL_X4         = 1, /* 4 samples for each conversion result */
  OVSRSEL_X8         = 2, /* 8 samples for each conversion result */
  OVSRSEL_X16        = 3, /* 16 samples for each conversion result */
  OVSRSEL_X32        = 4, /* 32 samples for each conversion result */
  OVSRSEL_X64        = 5, /* 64 samples for each conversion result */
  OVSRSEL_X128       = 6, /* 128 samples for each conversion result */
  OVSRSEL_X256       = 7, /* 256 samples for each conversion result */
  OVSRSEL_X512       = 8, /* 512 samples for each conversion result */
  OVSRSEL_X1024      = 9, /* 1024 samples for each conversion result */
  OVSRSEL_X2048      = 10, /* 2048 samples for each conversion result */
  OVSRSEL_X4096      = 11, /* 4096 samples for each conversion result */
} OVSRSEL_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 WARMUPMODE   : 2; /* RW: Warm-up Mode */
    REG32 PAD2         : 1;
    REG32 TAILGATE     : 1; /* RW: Conversion Tailgating */
    REG32 LPFMODE      : 2; /* RW: Low Pass Filter Mode */
    REG32 PAD6         : 2;
    REG32 PRESC        : 7; /* RW: Prescaler Setting */
    REG32 PAD15        : 1;
    REG32 TIMEBASE     : 7; /* RW: Time Base */
    REG32 PAD23        : 1;
    REG32 OVSRSEL      : 4; /* RW: Oversample Rate Select */
  };
} _0000; /* CTRL */

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLESTART  : 1; /* WO: Single Conversion Start */
    REG32 SINGLESTOP   : 1; /* WO: Single Conversion Stop */
    REG32 SCANSTART    : 1; /* WO: Scan Sequence Start */
    REG32 SCANSTOP     : 1; /* WO: Scan Sequence Stop */
  };
} _0004; /* CMD */

typedef enum {
  SCANDATASRC_CH0    = 0, /* Single ended mode: SCANDATA result originates from ADCn_CH0. Differential mode: SCANDATA result originates from ADCn_CH0-ADCn_CH1 */
  SCANDATASRC_CH1    = 1, /* Single ended mode: SCANDATA result originates from ADCn_CH1. Differential mode: SCANDATA result originates from ADCn_CH2_ADCn_CH3 */
  SCANDATASRC_CH2    = 2, /* Single ended mode: SCANDATA result originates from ADCn_CH2. Differential mode: SCANDATA result originates from ADCn_CH4-ADCn_CH5 */
  SCANDATASRC_CH3    = 3, /* Single ended mode: SCANDATA result originates from ADCn_CH3. Differential mode: SCANDATA result originates from ADCn_CH6-ADCn_CH7 */
  SCANDATASRC_CH4    = 4, /* SCANDATA result originates from ADCn_CH4 */
  SCANDATASRC_CH5    = 5, /* SCANDATA result originates from ADCn_CH5 */
  SCANDATASRC_CH6    = 6, /* SCANDATA result originates from ADCn_CH6 */
  SCANDATASRC_CH7    = 7, /* SCANDATA result originates from ADCn_CH7 */
} SCANDATASRC_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLEACT    : 1; /* RO: Single Conversion Active */
    REG32 SCANACT      : 1; /* RO: Scan Conversion Active */
    REG32 PAD2         : 6;
    REG32 SINGLEREFWARM : 1; /* RO: Single Reference Warmed Up */
    REG32 SCANREFWARM  : 1; /* RO: Scan Reference Warmed Up */
    REG32 PAD10        : 2;
    REG32 WARM         : 1; /* RO: ADC Warmed Up */
    REG32 PAD13        : 3;
    REG32 SINGLEDV     : 1; /* RO: Single Sample Data Valid */
    REG32 SCANDV       : 1; /* RO: Scan Data Valid */
    REG32 PAD18        : 6;
    REG32 SCANDATASRC  : 3; /* RO: Scan Data Source */
  };
} _0008; /* STATUS */

typedef enum {
  RES_12BIT          = 0, /* 12-bit resolution */
  RES_8BIT           = 1, /* 8-bit resolution */
  RES_6BIT           = 2, /* 6-bit resolution */
  RES_OVS            = 3, /* Oversampling enabled. Oversampling rate is set in OVSRSEL */
} RES_enum;

typedef enum {
  REF_1V25           = 0, /* Internal 1.25 V reference */
  REF_2V5            = 1, /* Internal 2.5 V reference */
  REF_VDD            = 2, /* Buffered VDD */
  REF_5VDIFF         = 3, /* Internal differential 5 V reference */
  REF_EXTSINGLE      = 4, /* Single ended external reference from ADCn_CH6 */
  REF_2XEXTDIFF      = 5, /* Differential external reference, 2x(ADCn_CH6 - ADCn_CH7) */
  REF_2XVDD          = 6, /* Unbuffered 2xVDD */
} REF_enum;

typedef enum {
  AT_1CYCLE          = 0, /* 1 ADC_CLK cycle acquisition time for single sample */
  AT_2CYCLES         = 1, /* 2 ADC_CLK cycles acquisition time for single sample */
  AT_4CYCLES         = 2, /* 4 ADC_CLK cycles acquisition time for single sample */
  AT_8CYCLES         = 3, /* 8 ADC_CLK cycles acquisition time for single sample */
  AT_16CYCLES        = 4, /* 16 ADC_CLK cycles acquisition time for single sample */
  AT_32CYCLES        = 5, /* 32 ADC_CLK cycles acquisition time for single sample */
  AT_64CYCLES        = 6, /* 64 ADC_CLK cycles acquisition time for single sample */
  AT_128CYCLES       = 7, /* 128 ADC_CLK cycles acquisition time for single sample */
  AT_256CYCLES       = 8, /* 256 ADC_CLK cycles acquisition time for single sample */
} AT_enum;

typedef enum {
  PRSSEL_PRSCH0      = 0, /* PRS ch 0 triggers single sample */
  PRSSEL_PRSCH1      = 1, /* PRS ch 1 triggers single sample */
  PRSSEL_PRSCH2      = 2, /* PRS ch 2 triggers single sample */
  PRSSEL_PRSCH3      = 3, /* PRS ch 3 triggers single sample */
  PRSSEL_PRSCH4      = 4, /* PRS ch 4 triggers single sample */
  PRSSEL_PRSCH5      = 5, /* PRS ch 5 triggers single sample */
  PRSSEL_PRSCH6      = 6, /* PRS ch 6 triggers single sample */
  PRSSEL_PRSCH7      = 7, /* PRS ch 7 triggers single sample */
  PRSSEL_PRSCH8      = 8, /* PRS ch 8 triggers single sample */
  PRSSEL_PRSCH9      = 9, /* PRS ch 9 triggers single sample */
  PRSSEL_PRSCH10     = 10, /* PRS ch 10 triggers single sample */
  PRSSEL_PRSCH11     = 11, /* PRS ch 11 triggers single sample */
} PRSSEL_enum;

typedef struct {
  union {
    REG32 REG;
    REG32 REP          : 1; /* RW: Single Sample Repetitive Mode */
    REG32 DIFF         : 1; /* RW: Single Sample Differential Mode */
    REG32 ADJ          : 1; /* RW: Single Sample Result Adjustment */
    REG32 PAD3         : 1;
    REG32 RES          : 2; /* RW: Single Sample Resolution Select */
    REG32 PAD6         : 2;
    REG32 INPUTSEL     : 4; /* RW: Single Sample Input Selection */
    REG32 PAD12        : 4;
    REG32 REF          : 3; /* RW: Single Sample Reference Selection */
    REG32 PAD19        : 1;
    REG32 AT           : 4; /* RW: Single Sample Acquisition Time */
    REG32 PRSEN        : 1; /* RW: Single Sample PRS Trigger Enable */
    REG32 PAD25        : 3;
    REG32 PRSSEL       : 4; /* RW: Single Sample PRS Trigger Select */
  };
} _000C; /* SINGLECTRL */

typedef struct {
  union {
    REG32 REG;
    REG32 REP          : 1; /* RW: Scan Sequence Repetitive Mode */
    REG32 DIFF         : 1; /* RW: Scan Sequence Differential Mode */
    REG32 ADJ          : 1; /* RW: Scan Sequence Result Adjustment */
    REG32 PAD3         : 1;
    REG32 RES          : 2; /* RW: Scan Sequence Resolution Select */
    REG32 PAD6         : 2;
    REG32 INPUTMASK    : 8; /* RW: Scan Sequence Input Mask */
    REG32 REF          : 3; /* RW: Scan Sequence Reference Selection */
    REG32 PAD19        : 1;
    REG32 AT           : 4; /* RW: Scan Sample Acquisition Time */
    REG32 PRSEN        : 1; /* RW: Scan Sequence PRS Trigger Enable */
    REG32 PAD25        : 3;
    REG32 PRSSEL       : 4; /* RW: Scan Sequence PRS Trigger Select */
  };
} _0010; /* SCANCTRL */

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLE       : 1; /* RW: Single Conversion Complete Interrupt Enable */
    REG32 SCAN         : 1; /* RW: Scan Conversion Complete Interrupt Enable */
    REG32 PAD2         : 6;
    REG32 SINGLEOF     : 1; /* RW: Single Result Overflow Interrupt Enable */
    REG32 SCANOF       : 1; /* RW: Scan Result Overflow Interrupt Enable */
  };
} _0014; /* IEN */

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLE       : 1; /* RO: Single Conversion Complete Interrupt Flag */
    REG32 SCAN         : 1; /* RO: Scan Conversion Complete Interrupt Flag */
    REG32 PAD2         : 6;
    REG32 SINGLEOF     : 1; /* RO: Single Result Overflow Interrupt Flag */
    REG32 SCANOF       : 1; /* RO: Scan Result Overflow Interrupt Flag */
  };
} _0018; /* IF */

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLE       : 1; /* WO: Single Conversion Complete Interrupt Flag Set */
    REG32 SCAN         : 1; /* WO: Scan Conversion Complete Interrupt Flag Set */
    REG32 PAD2         : 6;
    REG32 SINGLEOF     : 1; /* WO: Single Result Overflow Interrupt Flag Set */
    REG32 SCANOF       : 1; /* WO: Scan Result Overflow Interrupt Flag Set */
  };
} _001C; /* IFS */

typedef struct {
  union {
    REG32 REG;
    REG32 SINGLE       : 1; /* WO: Single Conversion Complete Interrupt Flag Clear */
    REG32 SCAN         : 1; /* WO: Scan Conversion Complete Interrupt Flag Clear */
    REG32 PAD2         : 6;
    REG32 SINGLEOF     : 1; /* WO: Single Result Overflow Interrupt Flag Clear */
    REG32 SCANOF       : 1; /* WO: Scan Result Overflow Interrupt Flag Clear */
  };
} _0020; /* IFC */

typedef REG32 _0024; /* SINGLEDATA */
typedef REG32 _0028; /* SCANDATA */
typedef REG32 _002C; /* SINGLEDATAP */
typedef REG32 _0030; /* SCANDATAP */
typedef struct {
  union {
    REG32 REG;
    REG32 SINGLEOFFSET : 7; /* RW: Single Mode Offset Calibration Value */
    REG32 PAD7         : 1;
    REG32 SINGLEGAIN   : 7; /* RW: Single Mode Gain Calibration Value */
    REG32 PAD15        : 1;
    REG32 SCANOFFSET   : 7; /* RW: Scan Mode Offset Calibration Value */
    REG32 PAD23        : 1;
    REG32 SCANGAIN     : 7; /* RW: Scan Mode Gain Calibration Value */
  };
} _0034; /* CAL */

typedef struct {
  union {
    REG32 REG;
    REG32 BIASPROG     : 4; /* RW: Bias Programming Value */
    REG32 PAD4         : 2;
    REG32 HALFBIAS     : 1; /* RW: Half Bias Current */
    REG32 PAD7         : 1;
    REG32 COMPBIAS     : 4; /* RW: Comparator Bias Value */
  };
} _003C; /* BIASPROG */


// Top-level register defs
typedef struct {
  _0000 CTRL;          /* RW: Control Register */
  _0004 CMD;           /* WO: Command Register */
  _0008 STATUS;        /* RO: Status Register */
  _000C SINGLECTRL;    /* RW: Single Sample Control Register */
  _0010 SCANCTRL;      /* RW: Scan Control Register */
  _0014 IEN;           /* RW: Interrupt Enable Register */
  _0018 IF;            /* RO: Interrupt Flag Register */
  _001C IFS;           /* WO: Interrupt Flag Set Register */
  _0020 IFC;           /* WO: Interrupt Flag Clear Register */
  _0024 SINGLEDATA;    /* RO: Single Conversion Result Data */
  _0028 SCANDATA;      /* RO: Scan Conversion Result Data */
  _002C SINGLEDATAP;   /* RO: Single Conversion Result Data Peek Register */
  _0030 SCANDATAP;     /* RO: Scan Sequence Result Data Peek Register */
  _0034 CAL;           /* RW: Calibration Register */
   PAD(0x38, 0x3c);
  _003C BIASPROG;      /* RW: Bias Programming Register */
} reg_t;
#define PF19D3F5F_FP 0x33afe0ca
#define PF19D3F5F_SZ 1024