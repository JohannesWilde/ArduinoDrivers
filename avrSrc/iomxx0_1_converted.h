/* Copyright (c) 2005 Anatoly Sokolov 
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.

   * Neither the name of the copyright holders nor the names of
     contributors may be used to endorse or promote products derived
     from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE. */

/* $Id: iomxx0_1.h 2235 2011-03-17 04:13:14Z arcanum $ */

/* avr/iomxx0_1.h - definitions for ATmega640, Atmega1280, ATmega1281,
   ATmega2560 and ATmega2561. */

#ifndef _AVR_IOMXX0_1_H_
#define _AVR_IOMXX0_1_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iomxx0_1.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

#if defined(__AVR_ATmega640__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
# define __ATmegaxx0__
#elif defined(__AVR_ATmega1281__) || defined(__AVR_ATmega2561__)
# define __ATmegaxx1__
#endif

/* Registers and associated bit numbers */

#define PINA_REGISTER 0X00
#define PINA_TYPE uint8_t
#define PINA_ACCESS _SFR_IO8
#define PINA PINA_ACCESS(PINA_REGISTER)
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

#define DDRA_REGISTER 0X01
#define DDRA_TYPE uint8_t
#define DDRA_ACCESS _SFR_IO8
#define DDRA DDRA_ACCESS(DDRA_REGISTER)
#define DDA7    7
#define DDA6    6
#define DDA5    5
#define DDA4    4
#define DDA3    3
#define DDA2    2
#define DDA1    1
#define DDA0    0

#define PORTA_REGISTER 0X02
#define PORTA_TYPE uint8_t
#define PORTA_ACCESS _SFR_IO8
#define PORTA PORTA_ACCESS(PORTA_REGISTER)
#define PA7     7
#define PA6     6
#define PA5     5
#define PA4     4
#define PA3     3
#define PA2     2
#define PA1     1
#define PA0     0

#define PINB_REGISTER 0X03
#define PINB_TYPE uint8_t
#define PINB_ACCESS _SFR_IO8
#define PINB PINB_ACCESS(PINB_REGISTER)
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB_REGISTER 0x04
#define DDRB_TYPE uint8_t
#define DDRB_ACCESS _SFR_IO8
#define DDRB DDRB_ACCESS(DDRB_REGISTER)
#define DDB7    7
#define DDB6    6
#define DDB5    5
#define DDB4    4
#define DDB3    3
#define DDB2    2
#define DDB1    1
#define DDB0    0

#define PORTB_REGISTER 0x05
#define PORTB_TYPE uint8_t
#define PORTB_ACCESS _SFR_IO8
#define PORTB PORTB_ACCESS(PORTB_REGISTER)
#define PB7     7
#define PB6     6
#define PB5     5
#define PB4     4
#define PB3     3
#define PB2     2
#define PB1     1
#define PB0     0

#define PINC_REGISTER 0x06
#define PINC_TYPE uint8_t
#define PINC_ACCESS _SFR_IO8
#define PINC PINC_ACCESS(PINC_REGISTER)
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

#define DDRC_REGISTER 0x07
#define DDRC_TYPE uint8_t
#define DDRC_ACCESS _SFR_IO8
#define DDRC DDRC_ACCESS(DDRC_REGISTER)
#define DDC7    7
#define DDC6    6
#define DDC5    5
#define DDC4    4
#define DDC3    3
#define DDC2    2
#define DDC1    1
#define DDC0    0

#define PORTC_REGISTER 0x08
#define PORTC_TYPE uint8_t
#define PORTC_ACCESS _SFR_IO8
#define PORTC PORTC_ACCESS(PORTC_REGISTER)
#define PC7     7
#define PC6     6
#define PC5     5
#define PC4     4
#define PC3     3
#define PC2     2
#define PC1     1
#define PC0     0

#define PIND_REGISTER 0x09
#define PIND_TYPE uint8_t
#define PIND_ACCESS _SFR_IO8
#define PIND PIND_ACCESS(PIND_REGISTER)
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0

#define DDRD_REGISTER 0x0A
#define DDRD_TYPE uint8_t
#define DDRD_ACCESS _SFR_IO8
#define DDRD DDRD_ACCESS(DDRD_REGISTER)
#define DDD7    7
#define DDD6    6
#define DDD5    5
#define DDD4    4
#define DDD3    3
#define DDD2    2
#define DDD1    1
#define DDD0    0

#define PORTD_REGISTER 0x0B
#define PORTD_TYPE uint8_t
#define PORTD_ACCESS _SFR_IO8
#define PORTD PORTD_ACCESS(PORTD_REGISTER)
#define PD7     7
#define PD6     6
#define PD5     5
#define PD4     4
#define PD3     3
#define PD2     2
#define PD1     1
#define PD0     0

#define PINE_REGISTER 0x0C
#define PINE_TYPE uint8_t
#define PINE_ACCESS _SFR_IO8
#define PINE PINE_ACCESS(PINE_REGISTER)
#define PINE7   7
#define PINE6   6
#define PINE5   5
#define PINE4   4
#define PINE3   3
#define PINE2   2
#define PINE1   1
#define PINE0   0

#define DDRE_REGISTER 0x0D
#define DDRE_TYPE uint8_t
#define DDRE_ACCESS _SFR_IO8
#define DDRE DDRE_ACCESS(DDRE_REGISTER)
#define DDE7    7
#define DDE6    6
#define DDE5    5
#define DDE4    4
#define DDE3    3
#define DDE2    2
#define DDE1    1
#define DDE0    0

#define PORTE_REGISTER 0x0E
#define PORTE_TYPE uint8_t
#define PORTE_ACCESS _SFR_IO8
#define PORTE PORTE_ACCESS(PORTE_REGISTER)
#define PE7     7
#define PE6     6
#define PE5     5
#define PE4     4
#define PE3     3
#define PE2     2
#define PE1     1
#define PE0     0

#define PINF_REGISTER 0x0F
#define PINF_TYPE uint8_t
#define PINF_ACCESS _SFR_IO8
#define PINF PINF_ACCESS(PINF_REGISTER)
#define PINF7   7
#define PINF6   6
#define PINF5   5
#define PINF4   4
#define PINF3   3
#define PINF2   2
#define PINF1   1
#define PINF0   0

#define DDRF_REGISTER 0x10
#define DDRF_TYPE uint8_t
#define DDRF_ACCESS _SFR_IO8
#define DDRF DDRF_ACCESS(DDRF_REGISTER)
#define DDF7    7
#define DDF6    6
#define DDF5    5
#define DDF4    4
#define DDF3    3
#define DDF2    2
#define DDF1    1
#define DDF0    0

#define PORTF_REGISTER 0x11
#define PORTF_TYPE uint8_t
#define PORTF_ACCESS _SFR_IO8
#define PORTF PORTF_ACCESS(PORTF_REGISTER)
#define PF7     7
#define PF6     6
#define PF5     5
#define PF4     4
#define PF3     3
#define PF2     2
#define PF1     1
#define PF0     0

#define PING_REGISTER 0x12
#define PING_TYPE uint8_t
#define PING_ACCESS _SFR_IO8
#define PING PING_ACCESS(PING_REGISTER)
#define PING5   5
#define PING4   4
#define PING3   3
#define PING2   2
#define PING1   1
#define PING0   0

#define DDRG_REGISTER 0x13
#define DDRG_TYPE uint8_t
#define DDRG_ACCESS _SFR_IO8
#define DDRG DDRG_ACCESS(DDRG_REGISTER)
#define DDG5    5
#define DDG4    4
#define DDG3    3
#define DDG2    2
#define DDG1    1
#define DDG0    0

#define PORTG_REGISTER 0x14
#define PORTG_TYPE uint8_t
#define PORTG_ACCESS _SFR_IO8
#define PORTG PORTG_ACCESS(PORTG_REGISTER)
#define PG5     5
#define PG4     4
#define PG3     3
#define PG2     2
#define PG1     1
#define PG0     0

#define TIFR0_REGISTER 0x15
#define TIFR0_TYPE uint8_t
#define TIFR0_ACCESS _SFR_IO8
#define TIFR0 TIFR0_ACCESS(TIFR0_REGISTER)
#define OCF0B   2
#define OCF0A   1
#define TOV0    0

#define TIFR1_REGISTER 0x16
#define TIFR1_TYPE uint8_t
#define TIFR1_ACCESS _SFR_IO8
#define TIFR1 TIFR1_ACCESS(TIFR1_REGISTER)
#define ICF1    5
#define OCF1C   3
#define OCF1B   2
#define OCF1A   1
#define TOV1    0

#define TIFR2_REGISTER 0x17
#define TIFR2_TYPE uint8_t
#define TIFR2_ACCESS _SFR_IO8
#define TIFR2 TIFR2_ACCESS(TIFR2_REGISTER)
#define OCF2B   2
#define OCF2A   1
#define TOV2    0

#define TIFR3_REGISTER 0x18
#define TIFR3_TYPE uint8_t
#define TIFR3_ACCESS _SFR_IO8
#define TIFR3 TIFR3_ACCESS(TIFR3_REGISTER)
#define ICF3    5
#define OCF3C   3
#define OCF3B   2
#define OCF3A   1
#define TOV3    0

#define TIFR4_REGISTER 0x19
#define TIFR4_TYPE uint8_t
#define TIFR4_ACCESS _SFR_IO8
#define TIFR4 TIFR4_ACCESS(TIFR4_REGISTER)
#define ICF4    5
#define OCF4C   3
#define OCF4B   2
#define OCF4A   1
#define TOV4    0

#define TIFR5_REGISTER 0x1A
#define TIFR5_TYPE uint8_t
#define TIFR5_ACCESS _SFR_IO8
#define TIFR5 TIFR5_ACCESS(TIFR5_REGISTER)
#define ICF5    5
#define OCF5C   3
#define OCF5B   2
#define OCF5A   1
#define TOV5    0

#define PCIFR_REGISTER 0x1B
#define PCIFR_TYPE uint8_t
#define PCIFR_ACCESS _SFR_IO8
#define PCIFR PCIFR_ACCESS(PCIFR_REGISTER)
#if defined(__ATmegaxx0__) 
# define PCIF2  2
#endif /* __ATmegaxx0__ */
#define PCIF1   1
#define PCIF0   0

#define EIFR_REGISTER 0x1C
#define EIFR_TYPE uint8_t
#define EIFR_ACCESS _SFR_IO8
#define EIFR EIFR_ACCESS(EIFR_REGISTER)
#define INTF7   7
#define INTF6   6
#define INTF5   5
#define INTF4   4
#define INTF3   3
#define INTF2   2
#define INTF1   1
#define INTF0   0

#define EIMSK_REGISTER 0x1D
#define EIMSK_TYPE uint8_t
#define EIMSK_ACCESS _SFR_IO8
#define EIMSK EIMSK_ACCESS(EIMSK_REGISTER)
#define INT7    7
#define INT6    6
#define INT5    5
#define INT4    4
#define INT3    3
#define INT2    2
#define INT1    1 
#define INT0    0

#define GPIOR0_REGISTER 0x1E
#define GPIOR0_TYPE uint8_t
#define GPIOR0_ACCESS _SFR_IO8
#define GPIOR0 GPIOR0_ACCESS(GPIOR0_REGISTER)

#define EECR_REGISTER 0x1F
#define EECR_TYPE uint8_t
#define EECR_ACCESS _SFR_IO8
#define EECR EECR_ACCESS(EECR_REGISTER)
#define EEPM1   5
#define EEPM0   4
#define EERIE   3
#define EEMPE   2
#define EEPE    1
#define EERE    0

#define EEDR_REGISTER 0X20
#define EEDR_TYPE uint8_t
#define EEDR_ACCESS _SFR_IO8
#define EEDR EEDR_ACCESS(EEDR_REGISTER)

/* Combine EEARL and EEARH */
#define EEAR_REGISTER 0x21
#define EEAR_TYPE uint16_t
#define EEAR_ACCESS _SFR_IO16
#define EEAR EEAR_ACCESS(EEAR_REGISTER)

#define EEARL_REGISTER 0x21
#define EEARL_TYPE uint8_t
#define EEARL_ACCESS _SFR_IO8
#define EEARL EEARL_ACCESS(EEARL_REGISTER)
#define EEARH_REGISTER 0X22
#define EEARH_TYPE uint8_t
#define EEARH_ACCESS _SFR_IO8
#define EEARH EEARH_ACCESS(EEARH_REGISTER)

/* 6-char sequence denoting where to find the EEPROM registers in memory space.
   Adresses denoted in hex syntax with uppercase letters. Used by the EEPROM
   subroutines.
   First two letters:  EECR address.
   Second two letters: EEDR address.
   Last two letters:   EEAR address.  */
#define __EEPROM_REG_LOCATIONS__ 1F2021

#define GTCCR_REGISTER 0x23
#define GTCCR_TYPE uint8_t
#define GTCCR_ACCESS _SFR_IO8
#define GTCCR GTCCR_ACCESS(GTCCR_REGISTER)
#define TSM     7
#define PSRASY  1
#define PSRSYNC 0

#define TCCR0A_REGISTER 0x24
#define TCCR0A_TYPE uint8_t
#define TCCR0A_ACCESS _SFR_IO8
#define TCCR0A TCCR0A_ACCESS(TCCR0A_REGISTER)
#define COM0A1  7
#define COM0A0  6
#define COM0B1  5
#define COM0B0  4
#define WGM01   1
#define WGM00   0

#define TCCR0B_REGISTER 0x25
#define TCCR0B_TYPE uint8_t
#define TCCR0B_ACCESS _SFR_IO8
#define TCCR0B TCCR0B_ACCESS(TCCR0B_REGISTER)
#define FOC0A   7
#define FOC0B   6
#define WGM02   3
#define CS02    2
#define CS01    1
#define CS00    0

#define TCNT0_REGISTER 0X26
#define TCNT0_TYPE uint8_t
#define TCNT0_ACCESS _SFR_IO8
#define TCNT0 TCNT0_ACCESS(TCNT0_REGISTER)

#define OCR0A_REGISTER 0X27
#define OCR0A_TYPE uint8_t
#define OCR0A_ACCESS _SFR_IO8
#define OCR0A OCR0A_ACCESS(OCR0A_REGISTER)

#define OCR0B_REGISTER 0X28
#define OCR0B_TYPE uint8_t
#define OCR0B_ACCESS _SFR_IO8
#define OCR0B OCR0B_ACCESS(OCR0B_REGISTER)

/* Reserved [0x29] */

#define GPIOR1_REGISTER 0x2A
#define GPIOR1_TYPE uint8_t
#define GPIOR1_ACCESS _SFR_IO8
#define GPIOR1 GPIOR1_ACCESS(GPIOR1_REGISTER)

#define GPIOR2_REGISTER 0x2B
#define GPIOR2_TYPE uint8_t
#define GPIOR2_ACCESS _SFR_IO8
#define GPIOR2 GPIOR2_ACCESS(GPIOR2_REGISTER)

#define SPCR_REGISTER 0x2C
#define SPCR_TYPE uint8_t
#define SPCR_ACCESS _SFR_IO8
#define SPCR SPCR_ACCESS(SPCR_REGISTER)
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

#define SPSR_REGISTER 0x2D
#define SPSR_TYPE uint8_t
#define SPSR_ACCESS _SFR_IO8
#define SPSR SPSR_ACCESS(SPSR_REGISTER)
#define SPIF    7
#define WCOL    6
#define SPI2X   0

#define SPDR_REGISTER 0X2E
#define SPDR_TYPE uint8_t
#define SPDR_ACCESS _SFR_IO8
#define SPDR SPDR_ACCESS(SPDR_REGISTER)

/* Reserved [0x2F] */

#define ACSR_REGISTER 0x30
#define ACSR_TYPE uint8_t
#define ACSR_ACCESS _SFR_IO8
#define ACSR ACSR_ACCESS(ACSR_REGISTER)
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIC    2
#define ACIS1   1
#define ACIS0   0

#define MONDR_REGISTER 0x31
#define MONDR_TYPE uint8_t
#define MONDR_ACCESS _SFR_IO8
#define MONDR MONDR_ACCESS(MONDR_REGISTER)
#define OCDR_REGISTER 0x31
#define OCDR_TYPE uint8_t
#define OCDR_ACCESS _SFR_IO8
#define OCDR OCDR_ACCESS(OCDR_REGISTER)
#define IDRD    7
#define OCDR7   7
#define OCDR6   6
#define OCDR5   5
#define OCDR4   4
#define OCDR3   3
#define OCDR2   2
#define OCDR1   1
#define OCDR0   0

/* Reserved [0x32] */

#define SMCR_REGISTER 0x33
#define SMCR_TYPE uint8_t
#define SMCR_ACCESS _SFR_IO8
#define SMCR SMCR_ACCESS(SMCR_REGISTER)
#define SM2     3
#define SM1     2
#define SM0     1
#define SE      0

#define MCUSR_REGISTER 0x34
#define MCUSR_TYPE uint8_t
#define MCUSR_ACCESS _SFR_IO8
#define MCUSR MCUSR_ACCESS(MCUSR_REGISTER)
#define JTRF    4
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

#define MCUCR_REGISTER 0X35
#define MCUCR_TYPE uint8_t
#define MCUCR_ACCESS _SFR_IO8
#define MCUCR MCUCR_ACCESS(MCUCR_REGISTER)
#define JTD     7
#define PUD     4
#define IVSEL   1
#define IVCE    0

/* Reserved [0x36] */

#define SPMCSR_REGISTER 0x37
#define SPMCSR_TYPE uint8_t
#define SPMCSR_ACCESS _SFR_IO8
#define SPMCSR SPMCSR_ACCESS(SPMCSR_REGISTER)
#define SPMIE   7
#define RWWSB   6
#define SIGRD   5
#define RWWSRE  4
#define BLBSET  3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

/* Reserved [0x38..0x3A] */

#define RAMPZ_REGISTER 0X3B
#define RAMPZ_TYPE uint8_t
#define RAMPZ_ACCESS _SFR_IO8
#define RAMPZ RAMPZ_ACCESS(RAMPZ_REGISTER)
#define RAMPZ0  0

#define EIND_REGISTER 0X3C
#define EIND_TYPE uint8_t
#define EIND_ACCESS _SFR_IO8
#define EIND EIND_ACCESS(EIND_REGISTER)
#define EIND0   0

/* SP [0x3D..0x3E] */
/* SREG [0x3F] */

#define WDTCSR_REGISTER 0x60
#define WDTCSR_TYPE uint8_t
#define WDTCSR_ACCESS _SFR_MEM8
#define WDTCSR WDTCSR_ACCESS(WDTCSR_REGISTER)
#define WDIF    7
#define WDIE    6
#define WDP3    5
#define WDCE    4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

#define CLKPR_REGISTER 0x61
#define CLKPR_TYPE uint8_t
#define CLKPR_ACCESS _SFR_MEM8
#define CLKPR CLKPR_ACCESS(CLKPR_REGISTER)
#define CLKPCE  7
#define CLKPS3  3
#define CLKPS2  2
#define CLKPS1  1
#define CLKPS0  0

/* Reserved [0x62..0x63] */

#define PRR0_REGISTER 0x64
#define PRR0_TYPE uint8_t
#define PRR0_ACCESS _SFR_MEM8
#define PRR0 PRR0_ACCESS(PRR0_REGISTER)
#define PRTWI       7
#define PRTIM2      6
#define PRTIM0      5
#define PRTIM1      3
#define PRSPI       2
#define PRUSART0    1
#define PRADC       0

#define __AVR_HAVE_PRR0	((1<<PRADC)|(1<<PRUSART0)|(1<<PRSPI)|(1<<PRTIM1)|(1<<PRTIM0)|(1<<PRTIM2)|(1<<PRTWI))
#define __AVR_HAVE_PRR0_PRADC
#define __AVR_HAVE_PRR0_PRUSART0
#define __AVR_HAVE_PRR0_PRSPI
#define __AVR_HAVE_PRR0_PRTIM1
#define __AVR_HAVE_PRR0_PRTIM0
#define __AVR_HAVE_PRR0_PRTIM2
#define __AVR_HAVE_PRR0_PRTWI

#define PRR1_REGISTER 0x65
#define PRR1_TYPE uint8_t
#define PRR1_ACCESS _SFR_MEM8
#define PRR1 PRR1_ACCESS(PRR1_REGISTER)
#define PRTIM5      5
#define PRTIM4      4
#define PRTIM3      3
#define PRUSART3    2
#define PRUSART2    1
#define PRUSART1    0

#define __AVR_HAVE_PRR1	((1<<PRUSART1)|(1<<PRUSART2)|(1<<PRUSART3)|(1<<PRTIM3)|(1<<PRTIM4)|(1<<PRTIM5))
#define __AVR_HAVE_PRR1_PRUSART1
#define __AVR_HAVE_PRR1_PRUSART2
#define __AVR_HAVE_PRR1_PRUSART3
#define __AVR_HAVE_PRR1_PRTIM3
#define __AVR_HAVE_PRR1_PRTIM4
#define __AVR_HAVE_PRR1_PRTIM5

#define OSCCAL_REGISTER 0x66
#define OSCCAL_TYPE uint8_t
#define OSCCAL_ACCESS _SFR_MEM8
#define OSCCAL OSCCAL_ACCESS(OSCCAL_REGISTER)

/* Reserved [0x67] */

#define PCICR_REGISTER 0x68
#define PCICR_TYPE uint8_t
#define PCICR_ACCESS _SFR_MEM8
#define PCICR PCICR_ACCESS(PCICR_REGISTER)
#if defined(__ATmegaxx0__)
# define PCIE2  2
#endif /* __ATmegaxx0__ */
#define PCIE1   1
#define PCIE0   0

#define EICRA_REGISTER 0x69
#define EICRA_TYPE uint8_t
#define EICRA_ACCESS _SFR_MEM8
#define EICRA EICRA_ACCESS(EICRA_REGISTER)
#define ISC31   7
#define ISC30   6
#define ISC21   5
#define ISC20   4
#define ISC11   3
#define ISC10   2
#define ISC01   1
#define ISC00   0

#define EICRB_REGISTER 0x6A
#define EICRB_TYPE uint8_t
#define EICRB_ACCESS _SFR_MEM8
#define EICRB EICRB_ACCESS(EICRB_REGISTER)
#define ISC71   7
#define ISC70   6
#define ISC61   5
#define ISC60   4
#define ISC51   3
#define ISC50   2
#define ISC41   1
#define ISC40   0

#define PCMSK0_REGISTER 0x6B
#define PCMSK0_TYPE uint8_t
#define PCMSK0_ACCESS _SFR_MEM8
#define PCMSK0 PCMSK0_ACCESS(PCMSK0_REGISTER)
#define PCINT7  7
#define PCINT6  6
#define PCINT5  5
#define PCINT4  4
#define PCINT3  3
#define PCINT2  2
#define PCINT1  1
#define PCINT0  0

#define PCMSK1_REGISTER 0x6C
#define PCMSK1_TYPE uint8_t
#define PCMSK1_ACCESS _SFR_MEM8
#define PCMSK1 PCMSK1_ACCESS(PCMSK1_REGISTER)
#define PCINT15 7
#define PCINT14 6
#define PCINT13 5
#define PCINT12 4
#define PCINT11 3
#define PCINT10 2
#define PCINT9  1
#define PCINT8  0

#if defined(__ATmegaxx0__) 
# define PCMSK2 _SFR_MEM8(0x6D)
# define PCINT23 7
# define PCINT22 6
# define PCINT21 5
# define PCINT20 4
# define PCINT19 3
# define PCINT18 2
# define PCINT17 1
# define PCINT16 0
#endif /* __ATmegaxx0__ */

#define TIMSK0_REGISTER 0x6E
#define TIMSK0_TYPE uint8_t
#define TIMSK0_ACCESS _SFR_MEM8
#define TIMSK0 TIMSK0_ACCESS(TIMSK0_REGISTER)
#define OCIE0B  2
#define OCIE0A  1
#define TOIE0   0

#define TIMSK1_REGISTER 0x6F
#define TIMSK1_TYPE uint8_t
#define TIMSK1_ACCESS _SFR_MEM8
#define TIMSK1 TIMSK1_ACCESS(TIMSK1_REGISTER)
#define ICIE1   5
#define OCIE1C  3
#define OCIE1B  2
#define OCIE1A  1
#define TOIE1   0

#define TIMSK2_REGISTER 0x70
#define TIMSK2_TYPE uint8_t
#define TIMSK2_ACCESS _SFR_MEM8
#define TIMSK2 TIMSK2_ACCESS(TIMSK2_REGISTER)
#define OCIE2B  2
#define OCIE2A  1
#define TOIE2   0

#define TIMSK3_REGISTER 0x71
#define TIMSK3_TYPE uint8_t
#define TIMSK3_ACCESS _SFR_MEM8
#define TIMSK3 TIMSK3_ACCESS(TIMSK3_REGISTER)
#define ICIE3   5
#define OCIE3C  3
#define OCIE3B  2
#define OCIE3A  1
#define TOIE3   0

#define TIMSK4_REGISTER 0x72
#define TIMSK4_TYPE uint8_t
#define TIMSK4_ACCESS _SFR_MEM8
#define TIMSK4 TIMSK4_ACCESS(TIMSK4_REGISTER)
#define ICIE4   5
#define OCIE4C  3
#define OCIE4B  2
#define OCIE4A  1
#define TOIE4   0

#define TIMSK5_REGISTER 0x73
#define TIMSK5_TYPE uint8_t
#define TIMSK5_ACCESS _SFR_MEM8
#define TIMSK5 TIMSK5_ACCESS(TIMSK5_REGISTER)
#define ICIE5   5
#define OCIE5C  3
#define OCIE5B  2
#define OCIE5A  1
#define TOIE5   0

#define XMCRA_REGISTER 0x74
#define XMCRA_TYPE uint8_t
#define XMCRA_ACCESS _SFR_MEM8
#define XMCRA XMCRA_ACCESS(XMCRA_REGISTER)
#define SRE     7
#define SRL2    6
#define SRL1    5
#define SRL0    4
#define SRW11   3
#define SRW10   2
#define SRW01   1
#define SRW00   0

#define XMCRB_REGISTER 0x75
#define XMCRB_TYPE uint8_t
#define XMCRB_ACCESS _SFR_MEM8
#define XMCRB XMCRB_ACCESS(XMCRB_REGISTER)
#define XMBK    7
#define XMM2    2
#define XMM1    1
#define XMM0    0

/* Reserved [0x76..0x77] */

/* Combine ADCL and ADCH */
#ifndef __ASSEMBLER__
#define ADC_REGISTER 0x78
#define ADC_TYPE uint16_t
#define ADC_ACCESS _SFR_MEM16
#define ADC ADC_ACCESS(ADC_REGISTER)
#endif
#define ADCW_REGISTER 0x78
#define ADCW_TYPE uint16_t
#define ADCW_ACCESS _SFR_MEM16
#define ADCW ADCW_ACCESS(ADCW_REGISTER)
#define ADCL_REGISTER 0x78
#define ADCL_TYPE uint8_t
#define ADCL_ACCESS _SFR_MEM8
#define ADCL ADCL_ACCESS(ADCL_REGISTER)
#define ADCH_REGISTER 0x79
#define ADCH_TYPE uint8_t
#define ADCH_ACCESS _SFR_MEM8
#define ADCH ADCH_ACCESS(ADCH_REGISTER)

#define ADCSRA_REGISTER 0x7A
#define ADCSRA_TYPE uint8_t
#define ADCSRA_ACCESS _SFR_MEM8
#define ADCSRA ADCSRA_ACCESS(ADCSRA_REGISTER)
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

#define ADCSRB_REGISTER 0x7B
#define ADCSRB_TYPE uint8_t
#define ADCSRB_ACCESS _SFR_MEM8
#define ADCSRB ADCSRB_ACCESS(ADCSRB_REGISTER)
#define ACME    6
#if defined(__ATmegaxx0__)
# define MUX5    3
#endif /* __ATmegaxx0__ */
#define ADTS2   2
#define ADTS1   1
#define ADTS0   0

#define ADMUX_REGISTER 0x7C
#define ADMUX_TYPE uint8_t
#define ADMUX_ACCESS _SFR_MEM8
#define ADMUX ADMUX_ACCESS(ADMUX_REGISTER)
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define DIDR2_REGISTER 0x7D
#define DIDR2_TYPE uint8_t
#define DIDR2_ACCESS _SFR_MEM8
#define DIDR2 DIDR2_ACCESS(DIDR2_REGISTER)
#define ADC15D  7
#define ADC14D  6
#define ADC13D  5
#define ADC12D  4
#define ADC11D  3
#define ADC10D  2
#define ADC9D   1
#define ADC8D   0

#define DIDR0_REGISTER 0x7E
#define DIDR0_TYPE uint8_t
#define DIDR0_ACCESS _SFR_MEM8
#define DIDR0 DIDR0_ACCESS(DIDR0_REGISTER)
#define ADC7D   7
#define ADC6D   6
#define ADC5D   5
#define ADC4D   4
#define ADC3D   3
#define ADC2D   2
#define ADC1D   1
#define ADC0D   0

#define DIDR1_REGISTER 0x7F
#define DIDR1_TYPE uint8_t
#define DIDR1_ACCESS _SFR_MEM8
#define DIDR1 DIDR1_ACCESS(DIDR1_REGISTER)
#define AIN1D   1
#define AIN0D   0

#define TCCR1A_REGISTER 0x80
#define TCCR1A_TYPE uint8_t
#define TCCR1A_ACCESS _SFR_MEM8
#define TCCR1A TCCR1A_ACCESS(TCCR1A_REGISTER)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define COM1C1  3
#define COM1C0  2
#define WGM11   1
#define WGM10   0

#define TCCR1B_REGISTER 0x81
#define TCCR1B_TYPE uint8_t
#define TCCR1B_ACCESS _SFR_MEM8
#define TCCR1B TCCR1B_ACCESS(TCCR1B_REGISTER)
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCCR1C_REGISTER 0x82
#define TCCR1C_TYPE uint8_t
#define TCCR1C_ACCESS _SFR_MEM8
#define TCCR1C TCCR1C_ACCESS(TCCR1C_REGISTER)
#define FOC1A   7
#define FOC1B   6
#define FOC1C   5

/* Reserved [0x83] */

/* Combine TCNT1L and TCNT1H */
#define TCNT1_REGISTER 0x84
#define TCNT1_TYPE uint16_t
#define TCNT1_ACCESS _SFR_MEM16
#define TCNT1 TCNT1_ACCESS(TCNT1_REGISTER)

#define TCNT1L_REGISTER 0x84
#define TCNT1L_TYPE uint8_t
#define TCNT1L_ACCESS _SFR_MEM8
#define TCNT1L TCNT1L_ACCESS(TCNT1L_REGISTER)
#define TCNT1H_REGISTER 0x85
#define TCNT1H_TYPE uint8_t
#define TCNT1H_ACCESS _SFR_MEM8
#define TCNT1H TCNT1H_ACCESS(TCNT1H_REGISTER)

/* Combine ICR1L and ICR1H */
#define ICR1_REGISTER 0x86
#define ICR1_TYPE uint16_t
#define ICR1_ACCESS _SFR_MEM16
#define ICR1 ICR1_ACCESS(ICR1_REGISTER)

#define ICR1L_REGISTER 0x86
#define ICR1L_TYPE uint8_t
#define ICR1L_ACCESS _SFR_MEM8
#define ICR1L ICR1L_ACCESS(ICR1L_REGISTER)
#define ICR1H_REGISTER 0x87
#define ICR1H_TYPE uint8_t
#define ICR1H_ACCESS _SFR_MEM8
#define ICR1H ICR1H_ACCESS(ICR1H_REGISTER)

/* Combine OCR1AL and OCR1AH */
#define OCR1A_REGISTER 0x88
#define OCR1A_TYPE uint16_t
#define OCR1A_ACCESS _SFR_MEM16
#define OCR1A OCR1A_ACCESS(OCR1A_REGISTER)

#define OCR1AL_REGISTER 0x88
#define OCR1AL_TYPE uint8_t
#define OCR1AL_ACCESS _SFR_MEM8
#define OCR1AL OCR1AL_ACCESS(OCR1AL_REGISTER)
#define OCR1AH_REGISTER 0x89
#define OCR1AH_TYPE uint8_t
#define OCR1AH_ACCESS _SFR_MEM8
#define OCR1AH OCR1AH_ACCESS(OCR1AH_REGISTER)

/* Combine OCR1BL and OCR1BH */
#define OCR1B_REGISTER 0x8A
#define OCR1B_TYPE uint16_t
#define OCR1B_ACCESS _SFR_MEM16
#define OCR1B OCR1B_ACCESS(OCR1B_REGISTER)

#define OCR1BL_REGISTER 0x8A
#define OCR1BL_TYPE uint8_t
#define OCR1BL_ACCESS _SFR_MEM8
#define OCR1BL OCR1BL_ACCESS(OCR1BL_REGISTER)
#define OCR1BH_REGISTER 0x8B
#define OCR1BH_TYPE uint8_t
#define OCR1BH_ACCESS _SFR_MEM8
#define OCR1BH OCR1BH_ACCESS(OCR1BH_REGISTER)

/* Combine OCR1CL and OCR1CH */
#define OCR1C_REGISTER 0x8C
#define OCR1C_TYPE uint16_t
#define OCR1C_ACCESS _SFR_MEM16
#define OCR1C OCR1C_ACCESS(OCR1C_REGISTER)

#define OCR1CL_REGISTER 0x8C
#define OCR1CL_TYPE uint8_t
#define OCR1CL_ACCESS _SFR_MEM8
#define OCR1CL OCR1CL_ACCESS(OCR1CL_REGISTER)
#define OCR1CH_REGISTER 0x8D
#define OCR1CH_TYPE uint8_t
#define OCR1CH_ACCESS _SFR_MEM8
#define OCR1CH OCR1CH_ACCESS(OCR1CH_REGISTER)

/* Reserved [0x8E..0x8F] */

#define TCCR3A_REGISTER 0x90
#define TCCR3A_TYPE uint8_t
#define TCCR3A_ACCESS _SFR_MEM8
#define TCCR3A TCCR3A_ACCESS(TCCR3A_REGISTER)
#define COM3A1  7
#define COM3A0  6
#define COM3B1  5
#define COM3B0  4
#define COM3C1  3
#define COM3C0  2
#define WGM31   1
#define WGM30   0

#define TCCR3B_REGISTER 0x91
#define TCCR3B_TYPE uint8_t
#define TCCR3B_ACCESS _SFR_MEM8
#define TCCR3B TCCR3B_ACCESS(TCCR3B_REGISTER)
#define ICNC3   7
#define ICES3   6
#define WGM33   4
#define WGM32   3
#define CS32    2
#define CS31    1
#define CS30    0

#define TCCR3C_REGISTER 0x92
#define TCCR3C_TYPE uint8_t
#define TCCR3C_ACCESS _SFR_MEM8
#define TCCR3C TCCR3C_ACCESS(TCCR3C_REGISTER)
#define FOC3A   7
#define FOC3B   6
#define FOC3C   5

/* Reserved [0x93] */

/* Combine TCNT3L and TCNT3H */
#define TCNT3_REGISTER 0x94
#define TCNT3_TYPE uint16_t
#define TCNT3_ACCESS _SFR_MEM16
#define TCNT3 TCNT3_ACCESS(TCNT3_REGISTER)

#define TCNT3L_REGISTER 0x94
#define TCNT3L_TYPE uint8_t
#define TCNT3L_ACCESS _SFR_MEM8
#define TCNT3L TCNT3L_ACCESS(TCNT3L_REGISTER)
#define TCNT3H_REGISTER 0x95
#define TCNT3H_TYPE uint8_t
#define TCNT3H_ACCESS _SFR_MEM8
#define TCNT3H TCNT3H_ACCESS(TCNT3H_REGISTER)

/* Combine ICR3L and ICR3H */
#define ICR3_REGISTER 0x96
#define ICR3_TYPE uint16_t
#define ICR3_ACCESS _SFR_MEM16
#define ICR3 ICR3_ACCESS(ICR3_REGISTER)

#define ICR3L_REGISTER 0x96
#define ICR3L_TYPE uint8_t
#define ICR3L_ACCESS _SFR_MEM8
#define ICR3L ICR3L_ACCESS(ICR3L_REGISTER)
#define ICR3H_REGISTER 0x97
#define ICR3H_TYPE uint8_t
#define ICR3H_ACCESS _SFR_MEM8
#define ICR3H ICR3H_ACCESS(ICR3H_REGISTER)

/* Combine OCR3AL and OCR3AH */
#define OCR3A_REGISTER 0x98
#define OCR3A_TYPE uint16_t
#define OCR3A_ACCESS _SFR_MEM16
#define OCR3A OCR3A_ACCESS(OCR3A_REGISTER)

#define OCR3AL_REGISTER 0x98
#define OCR3AL_TYPE uint8_t
#define OCR3AL_ACCESS _SFR_MEM8
#define OCR3AL OCR3AL_ACCESS(OCR3AL_REGISTER)
#define OCR3AH_REGISTER 0x99
#define OCR3AH_TYPE uint8_t
#define OCR3AH_ACCESS _SFR_MEM8
#define OCR3AH OCR3AH_ACCESS(OCR3AH_REGISTER)

/* Combine OCR3BL and OCR3BH */
#define OCR3B_REGISTER 0x9A
#define OCR3B_TYPE uint16_t
#define OCR3B_ACCESS _SFR_MEM16
#define OCR3B OCR3B_ACCESS(OCR3B_REGISTER)

#define OCR3BL_REGISTER 0x9A
#define OCR3BL_TYPE uint8_t
#define OCR3BL_ACCESS _SFR_MEM8
#define OCR3BL OCR3BL_ACCESS(OCR3BL_REGISTER)
#define OCR3BH_REGISTER 0x9B
#define OCR3BH_TYPE uint8_t
#define OCR3BH_ACCESS _SFR_MEM8
#define OCR3BH OCR3BH_ACCESS(OCR3BH_REGISTER)

/* Combine OCR3CL and OCR3CH */
#define OCR3C_REGISTER 0x9C
#define OCR3C_TYPE uint16_t
#define OCR3C_ACCESS _SFR_MEM16
#define OCR3C OCR3C_ACCESS(OCR3C_REGISTER)

#define OCR3CL_REGISTER 0x9C
#define OCR3CL_TYPE uint8_t
#define OCR3CL_ACCESS _SFR_MEM8
#define OCR3CL OCR3CL_ACCESS(OCR3CL_REGISTER)
#define OCR3CH_REGISTER 0x9D
#define OCR3CH_TYPE uint8_t
#define OCR3CH_ACCESS _SFR_MEM8
#define OCR3CH OCR3CH_ACCESS(OCR3CH_REGISTER)

/* Reserved [0x9E..0x9F] */

#define TCCR4A_REGISTER 0xA0
#define TCCR4A_TYPE uint8_t
#define TCCR4A_ACCESS _SFR_MEM8
#define TCCR4A TCCR4A_ACCESS(TCCR4A_REGISTER)
#define COM4A1  7
#define COM4A0  6
#define COM4B1  5
#define COM4B0  4
#define COM4C1  3
#define COM4C0  2
#define WGM41   1
#define WGM40   0

#define TCCR4B_REGISTER 0xA1
#define TCCR4B_TYPE uint8_t
#define TCCR4B_ACCESS _SFR_MEM8
#define TCCR4B TCCR4B_ACCESS(TCCR4B_REGISTER)
#define ICNC4   7
#define ICES4   6
#define WGM43   4
#define WGM42   3
#define CS42    2
#define CS41    1
#define CS40    0

#define TCCR4C_REGISTER 0xA2
#define TCCR4C_TYPE uint8_t
#define TCCR4C_ACCESS _SFR_MEM8
#define TCCR4C TCCR4C_ACCESS(TCCR4C_REGISTER)
#define FOC4A   7
#define FOC4B   6
#define FOC4C   5

/* Reserved [0xA3] */

/* Combine TCNT4L and TCNT4H */
#define TCNT4_REGISTER 0xA4
#define TCNT4_TYPE uint16_t
#define TCNT4_ACCESS _SFR_MEM16
#define TCNT4 TCNT4_ACCESS(TCNT4_REGISTER)

#define TCNT4L_REGISTER 0xA4
#define TCNT4L_TYPE uint8_t
#define TCNT4L_ACCESS _SFR_MEM8
#define TCNT4L TCNT4L_ACCESS(TCNT4L_REGISTER)
#define TCNT4H_REGISTER 0xA5
#define TCNT4H_TYPE uint8_t
#define TCNT4H_ACCESS _SFR_MEM8
#define TCNT4H TCNT4H_ACCESS(TCNT4H_REGISTER)

/* Combine ICR4L and ICR4H */
#define ICR4_REGISTER 0xA6
#define ICR4_TYPE uint16_t
#define ICR4_ACCESS _SFR_MEM16
#define ICR4 ICR4_ACCESS(ICR4_REGISTER)

#define ICR4L_REGISTER 0xA6
#define ICR4L_TYPE uint8_t
#define ICR4L_ACCESS _SFR_MEM8
#define ICR4L ICR4L_ACCESS(ICR4L_REGISTER)
#define ICR4H_REGISTER 0xA7
#define ICR4H_TYPE uint8_t
#define ICR4H_ACCESS _SFR_MEM8
#define ICR4H ICR4H_ACCESS(ICR4H_REGISTER)

/* Combine OCR4AL and OCR4AH */
#define OCR4A_REGISTER 0xA8
#define OCR4A_TYPE uint16_t
#define OCR4A_ACCESS _SFR_MEM16
#define OCR4A OCR4A_ACCESS(OCR4A_REGISTER)

#define OCR4AL_REGISTER 0xA8
#define OCR4AL_TYPE uint8_t
#define OCR4AL_ACCESS _SFR_MEM8
#define OCR4AL OCR4AL_ACCESS(OCR4AL_REGISTER)
#define OCR4AH_REGISTER 0xA9
#define OCR4AH_TYPE uint8_t
#define OCR4AH_ACCESS _SFR_MEM8
#define OCR4AH OCR4AH_ACCESS(OCR4AH_REGISTER)

/* Combine OCR4BL and OCR4BH */
#define OCR4B_REGISTER 0xAA
#define OCR4B_TYPE uint16_t
#define OCR4B_ACCESS _SFR_MEM16
#define OCR4B OCR4B_ACCESS(OCR4B_REGISTER)

#define OCR4BL_REGISTER 0xAA
#define OCR4BL_TYPE uint8_t
#define OCR4BL_ACCESS _SFR_MEM8
#define OCR4BL OCR4BL_ACCESS(OCR4BL_REGISTER)
#define OCR4BH_REGISTER 0xAB
#define OCR4BH_TYPE uint8_t
#define OCR4BH_ACCESS _SFR_MEM8
#define OCR4BH OCR4BH_ACCESS(OCR4BH_REGISTER)

/* Combine OCR4CL and OCR4CH */
#define OCR4C_REGISTER 0xAC
#define OCR4C_TYPE uint16_t
#define OCR4C_ACCESS _SFR_MEM16
#define OCR4C OCR4C_ACCESS(OCR4C_REGISTER)

#define OCR4CL_REGISTER 0xAC
#define OCR4CL_TYPE uint8_t
#define OCR4CL_ACCESS _SFR_MEM8
#define OCR4CL OCR4CL_ACCESS(OCR4CL_REGISTER)
#define OCR4CH_REGISTER 0xAD
#define OCR4CH_TYPE uint8_t
#define OCR4CH_ACCESS _SFR_MEM8
#define OCR4CH OCR4CH_ACCESS(OCR4CH_REGISTER)

/* Reserved [0xAE..0xAF] */

#define TCCR2A_REGISTER 0xB0
#define TCCR2A_TYPE uint8_t
#define TCCR2A_ACCESS _SFR_MEM8
#define TCCR2A TCCR2A_ACCESS(TCCR2A_REGISTER)
#define COM2A1  7
#define COM2A0  6
#define COM2B1  5
#define COM2B0  4
#define WGM21   1
#define WGM20   0

#define TCCR2B_REGISTER 0xB1
#define TCCR2B_TYPE uint8_t
#define TCCR2B_ACCESS _SFR_MEM8
#define TCCR2B TCCR2B_ACCESS(TCCR2B_REGISTER)
#define FOC2A   7
#define FOC2B   6
#define WGM22   3
#define CS22    2
#define CS21    1
#define CS20    0

#define TCNT2_REGISTER 0xB2
#define TCNT2_TYPE uint8_t
#define TCNT2_ACCESS _SFR_MEM8
#define TCNT2 TCNT2_ACCESS(TCNT2_REGISTER)

#define OCR2A_REGISTER 0xB3
#define OCR2A_TYPE uint8_t
#define OCR2A_ACCESS _SFR_MEM8
#define OCR2A OCR2A_ACCESS(OCR2A_REGISTER)

#define OCR2B_REGISTER 0xB4
#define OCR2B_TYPE uint8_t
#define OCR2B_ACCESS _SFR_MEM8
#define OCR2B OCR2B_ACCESS(OCR2B_REGISTER)

/* Reserved [0xB5] */

#define ASSR_REGISTER 0xB6
#define ASSR_TYPE uint8_t
#define ASSR_ACCESS _SFR_MEM8
#define ASSR ASSR_ACCESS(ASSR_REGISTER)
#define EXCLK   6
#define AS2     5
#define TCN2UB  4
#define OCR2AUB 3
#define OCR2BUB 2
#define TCR2AUB 1
#define TCR2BUB 0

/* Reserved [0xB7] */

#define TWBR_REGISTER 0xB8
#define TWBR_TYPE uint8_t
#define TWBR_ACCESS _SFR_MEM8
#define TWBR TWBR_ACCESS(TWBR_REGISTER)

#define TWSR_REGISTER 0xB9
#define TWSR_TYPE uint8_t
#define TWSR_ACCESS _SFR_MEM8
#define TWSR TWSR_ACCESS(TWSR_REGISTER)
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
#define TWPS1   1
#define TWPS0   0

#define TWAR_REGISTER 0xBA
#define TWAR_TYPE uint8_t
#define TWAR_ACCESS _SFR_MEM8
#define TWAR TWAR_ACCESS(TWAR_REGISTER)
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

#define TWDR_REGISTER 0xBB
#define TWDR_TYPE uint8_t
#define TWDR_ACCESS _SFR_MEM8
#define TWDR TWDR_ACCESS(TWDR_REGISTER)

#define TWCR_REGISTER 0xBC
#define TWCR_TYPE uint8_t
#define TWCR_ACCESS _SFR_MEM8
#define TWCR TWCR_ACCESS(TWCR_REGISTER)
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

#define TWAMR_REGISTER 0xBD
#define TWAMR_TYPE uint8_t
#define TWAMR_ACCESS _SFR_MEM8
#define TWAMR TWAMR_ACCESS(TWAMR_REGISTER)
#define TWAM6   7
#define TWAM5   6
#define TWAM4   5
#define TWAM3   4
#define TWAM2   3
#define TWAM1   2
#define TWAM0   1

/* Reserved [0xBE..0xBF] */

#define UCSR0A_REGISTER 0xC0
#define UCSR0A_TYPE uint8_t
#define UCSR0A_ACCESS _SFR_MEM8
#define UCSR0A UCSR0A_ACCESS(UCSR0A_REGISTER)
#define RXC0    7
#define TXC0    6
#define UDRE0   5
#define FE0     4
#define DOR0    3
#define UPE0    2
#define U2X0    1
#define MPCM0   0

#define UCSR0B_REGISTER 0XC1
#define UCSR0B_TYPE uint8_t
#define UCSR0B_ACCESS _SFR_MEM8
#define UCSR0B UCSR0B_ACCESS(UCSR0B_REGISTER)
#define RXCIE0  7
#define TXCIE0  6
#define UDRIE0  5
#define RXEN0   4
#define TXEN0   3
#define UCSZ02  2
#define RXB80   1
#define TXB80   0

#define UCSR0C_REGISTER 0xC2
#define UCSR0C_TYPE uint8_t
#define UCSR0C_ACCESS _SFR_MEM8
#define UCSR0C UCSR0C_ACCESS(UCSR0C_REGISTER)
#define UMSEL01 7
#define UMSEL00 6
#define UPM01   5
#define UPM00   4
#define USBS0   3
#define UCSZ01  2
#define UCSZ00  1
#define UCPOL0  0

/* Reserved [0xC3] */

/* Combine UBRR0L and UBRR0H */
#define UBRR0_REGISTER 0xC4
#define UBRR0_TYPE uint16_t
#define UBRR0_ACCESS _SFR_MEM16
#define UBRR0 UBRR0_ACCESS(UBRR0_REGISTER)

#define UBRR0L_REGISTER 0xC4
#define UBRR0L_TYPE uint8_t
#define UBRR0L_ACCESS _SFR_MEM8
#define UBRR0L UBRR0L_ACCESS(UBRR0L_REGISTER)
#define UBRR0H_REGISTER 0xC5
#define UBRR0H_TYPE uint8_t
#define UBRR0H_ACCESS _SFR_MEM8
#define UBRR0H UBRR0H_ACCESS(UBRR0H_REGISTER)

#define UDR0_REGISTER 0XC6
#define UDR0_TYPE uint8_t
#define UDR0_ACCESS _SFR_MEM8
#define UDR0 UDR0_ACCESS(UDR0_REGISTER)

/* Reserved [0xC7] */

#define UCSR1A_REGISTER 0xC8
#define UCSR1A_TYPE uint8_t
#define UCSR1A_ACCESS _SFR_MEM8
#define UCSR1A UCSR1A_ACCESS(UCSR1A_REGISTER)
#define RXC1    7
#define TXC1    6
#define UDRE1   5
#define FE1     4
#define DOR1    3
#define UPE1    2
#define U2X1    1
#define MPCM1   0

#define UCSR1B_REGISTER 0XC9
#define UCSR1B_TYPE uint8_t
#define UCSR1B_ACCESS _SFR_MEM8
#define UCSR1B UCSR1B_ACCESS(UCSR1B_REGISTER)
#define RXCIE1  7
#define TXCIE1  6
#define UDRIE1  5
#define RXEN1   4
#define TXEN1   3
#define UCSZ12  2
#define RXB81   1
#define TXB81   0

#define UCSR1C_REGISTER 0xCA
#define UCSR1C_TYPE uint8_t
#define UCSR1C_ACCESS _SFR_MEM8
#define UCSR1C UCSR1C_ACCESS(UCSR1C_REGISTER)
#define UMSEL11 7
#define UMSEL10 6
#define UPM11   5
#define UPM10   4
#define USBS1   3
#define UCSZ11  2
#define UCSZ10  1
#define UCPOL1  0

/* Reserved [0xCB] */

/* Combine UBRR1L and UBRR1H */
#define UBRR1_REGISTER 0xCC
#define UBRR1_TYPE uint16_t
#define UBRR1_ACCESS _SFR_MEM16
#define UBRR1 UBRR1_ACCESS(UBRR1_REGISTER)

#define UBRR1L_REGISTER 0xCC
#define UBRR1L_TYPE uint8_t
#define UBRR1L_ACCESS _SFR_MEM8
#define UBRR1L UBRR1L_ACCESS(UBRR1L_REGISTER)
#define UBRR1H_REGISTER 0xCD
#define UBRR1H_TYPE uint8_t
#define UBRR1H_ACCESS _SFR_MEM8
#define UBRR1H UBRR1H_ACCESS(UBRR1H_REGISTER)

#define UDR1_REGISTER 0XCE
#define UDR1_TYPE uint8_t
#define UDR1_ACCESS _SFR_MEM8
#define UDR1 UDR1_ACCESS(UDR1_REGISTER)

/* Reserved [0xCF] */

#if defined(__ATmegaxx0__)

# define UCSR2A _SFR_MEM8(0xD0)
# define RXC2   7
# define TXC2   6
# define UDRE2  5
# define FE2    4
# define DOR2   3
# define UPE2   2
# define U2X2   1
# define MPCM2  0

# define UCSR2B _SFR_MEM8(0XD1)
# define RXCIE2 7
# define TXCIE2 6
# define UDRIE2 5
# define RXEN2  4
# define TXEN2  3
# define UCSZ22 2
# define RXB82  1
# define TXB82  0

# define UCSR2C _SFR_MEM8(0xD2)
# define UMSEL21 7
# define UMSEL20 6
# define UPM21  5
# define UPM20  4
# define USBS2  3
# define UCSZ21 2
# define UCSZ20 1
# define UCPOL2 0

/* Reserved [0xD3] */

/* Combine UBRR2L and UBRR2H */
# define UBRR2  _SFR_MEM16(0xD4)

# define UBRR2L _SFR_MEM8(0xD4)
# define UBRR2H _SFR_MEM8(0xD5)

# define UDR2   _SFR_MEM8(0XD6)

#endif /* __ATmegaxx0__ */

/* Reserved [0xD7..0xFF] */

#if defined(__ATmegaxx0__)

# define PINH   _SFR_MEM8(0x100)
# define PINH7  7
# define PINH6  6
# define PINH5  5
# define PINH4  4
# define PINH3  3
# define PINH2  2
# define PINH1  1
# define PINH0  0

# define DDRH   _SFR_MEM8(0x101)
# define DDH7   7
# define DDH6   6
# define DDH5   5
# define DDH4   4
# define DDH3   3
# define DDH2   2
# define DDH1   1
# define DDH0   0

# define PORTH  _SFR_MEM8(0x102)
# define PH7    7
# define PH6    6
# define PH5    5
# define PH4    4
# define PH3    3
# define PH2    2
# define PH1    1
# define PH0    0

# define PINJ   _SFR_MEM8(0x103)
# define PINJ7  7
# define PINJ6  6
# define PINJ5  5
# define PINJ4  4
# define PINJ3  3
# define PINJ2  2
# define PINJ1  1
# define PINJ0  0

# define DDRJ   _SFR_MEM8(0x104)
# define DDJ7   7
# define DDJ6   6
# define DDJ5   5
# define DDJ4   4
# define DDJ3   3
# define DDJ2   2
# define DDJ1   1
# define DDJ0   0

# define PORTJ  _SFR_MEM8(0x105)
# define PJ7 7
# define PJ6 6
# define PJ5 5
# define PJ4 4
# define PJ3 3
# define PJ2 2
# define PJ1 1
# define PJ0 0

# define PINK   _SFR_MEM8(0x106)
# define PINK7  7
# define PINK6  6
# define PINK5  5
# define PINK4  4
# define PINK3  3
# define PINK2  2
# define PINK1  1
# define PINK0  0

# define DDRK   _SFR_MEM8(0x107)
# define DDK7   7
# define DDK6   6
# define DDK5   5
# define DDK4   4
# define DDK3   3
# define DDK2   2
# define DDK1   1
# define DDK0   0

# define PORTK  _SFR_MEM8(0x108)
# define PK7 7
# define PK6 6
# define PK5 5
# define PK4 4
# define PK3 3
# define PK2 2
# define PK1 1
# define PK0 0

# define PINL   _SFR_MEM8(0x109)
# define PINL7  7
# define PINL6  6
# define PINL5  5
# define PINL4  4
# define PINL3  3
# define PINL2  2
# define PINL1  1
# define PINL0  0

# define DDRL   _SFR_MEM8(0x10A)
# define DDL7   7
# define DDL6   6
# define DDL5   5
# define DDL4   4
# define DDL3   3
# define DDL2   2
# define DDL1   1
# define DDL0   0

# define PORTL  _SFR_MEM8(0x10B)
# define PL7 7
# define PL6 6
# define PL5 5
# define PL4 4
# define PL3 3
# define PL2 2
# define PL1 1
# define PL0 0

#endif /* __ATmegaxx0__ */

/* Reserved [0x10C..0x11F] */

#define TCCR5A_REGISTER 0x120
#define TCCR5A_TYPE uint8_t
#define TCCR5A_ACCESS _SFR_MEM8
#define TCCR5A TCCR5A_ACCESS(TCCR5A_REGISTER)
#define COM5A1  7
#define COM5A0  6
#define COM5B1  5
#define COM5B0  4
#define COM5C1  3
#define COM5C0  2
#define WGM51   1
#define WGM50   0

#define TCCR5B_REGISTER 0x121
#define TCCR5B_TYPE uint8_t
#define TCCR5B_ACCESS _SFR_MEM8
#define TCCR5B TCCR5B_ACCESS(TCCR5B_REGISTER)
#define ICNC5   7
#define ICES5   6
#define WGM53   4
#define WGM52   3
#define CS52    2
#define CS51    1
#define CS50    0

#define TCCR5C_REGISTER 0x122
#define TCCR5C_TYPE uint8_t
#define TCCR5C_ACCESS _SFR_MEM8
#define TCCR5C TCCR5C_ACCESS(TCCR5C_REGISTER)
#define FOC5A   7
#define FOC5B   6
#define FOC5C   5

/* Reserved [0x123] */

/* Combine TCNT5L and TCNT5H */
#define TCNT5_REGISTER 0x124
#define TCNT5_TYPE uint16_t
#define TCNT5_ACCESS _SFR_MEM16
#define TCNT5 TCNT5_ACCESS(TCNT5_REGISTER)

#define TCNT5L_REGISTER 0x124
#define TCNT5L_TYPE uint8_t
#define TCNT5L_ACCESS _SFR_MEM8
#define TCNT5L TCNT5L_ACCESS(TCNT5L_REGISTER)
#define TCNT5H_REGISTER 0x125
#define TCNT5H_TYPE uint8_t
#define TCNT5H_ACCESS _SFR_MEM8
#define TCNT5H TCNT5H_ACCESS(TCNT5H_REGISTER)

/* Combine ICR5L and ICR5H */
#define ICR5_REGISTER 0x126
#define ICR5_TYPE uint16_t
#define ICR5_ACCESS _SFR_MEM16
#define ICR5 ICR5_ACCESS(ICR5_REGISTER)

#define ICR5L_REGISTER 0x126
#define ICR5L_TYPE uint8_t
#define ICR5L_ACCESS _SFR_MEM8
#define ICR5L ICR5L_ACCESS(ICR5L_REGISTER)
#define ICR5H_REGISTER 0x127
#define ICR5H_TYPE uint8_t
#define ICR5H_ACCESS _SFR_MEM8
#define ICR5H ICR5H_ACCESS(ICR5H_REGISTER)

/* Combine OCR5AL and OCR5AH */
#define OCR5A_REGISTER 0x128
#define OCR5A_TYPE uint16_t
#define OCR5A_ACCESS _SFR_MEM16
#define OCR5A OCR5A_ACCESS(OCR5A_REGISTER)

#define OCR5AL_REGISTER 0x128
#define OCR5AL_TYPE uint8_t
#define OCR5AL_ACCESS _SFR_MEM8
#define OCR5AL OCR5AL_ACCESS(OCR5AL_REGISTER)
#define OCR5AH_REGISTER 0x129
#define OCR5AH_TYPE uint8_t
#define OCR5AH_ACCESS _SFR_MEM8
#define OCR5AH OCR5AH_ACCESS(OCR5AH_REGISTER)

/* Combine OCR5BL and OCR5BH */
#define OCR5B_REGISTER 0x12A
#define OCR5B_TYPE uint16_t
#define OCR5B_ACCESS _SFR_MEM16
#define OCR5B OCR5B_ACCESS(OCR5B_REGISTER)

#define OCR5BL_REGISTER 0x12A
#define OCR5BL_TYPE uint8_t
#define OCR5BL_ACCESS _SFR_MEM8
#define OCR5BL OCR5BL_ACCESS(OCR5BL_REGISTER)
#define OCR5BH_REGISTER 0x12B
#define OCR5BH_TYPE uint8_t
#define OCR5BH_ACCESS _SFR_MEM8
#define OCR5BH OCR5BH_ACCESS(OCR5BH_REGISTER)

/* Combine OCR5CL and OCR5CH */
#define OCR5C_REGISTER 0x12C
#define OCR5C_TYPE uint16_t
#define OCR5C_ACCESS _SFR_MEM16
#define OCR5C OCR5C_ACCESS(OCR5C_REGISTER)

#define OCR5CL_REGISTER 0x12C
#define OCR5CL_TYPE uint8_t
#define OCR5CL_ACCESS _SFR_MEM8
#define OCR5CL OCR5CL_ACCESS(OCR5CL_REGISTER)
#define OCR5CH_REGISTER 0x12D
#define OCR5CH_TYPE uint8_t
#define OCR5CH_ACCESS _SFR_MEM8
#define OCR5CH OCR5CH_ACCESS(OCR5CH_REGISTER)

/* Reserved [0x12E..0x12F] */

#if defined(__ATmegaxx0__) 

# define UCSR3A _SFR_MEM8(0x130)
# define RXC3   7
# define TXC3   6
# define UDRE3  5
# define FE3    4
# define DOR3   3
# define UPE3   2
# define U2X3   1
# define MPCM3  0

# define UCSR3B _SFR_MEM8(0X131)
# define RXCIE3 7
# define TXCIE3 6
# define UDRIE3 5
# define RXEN3  4
# define TXEN3  3
# define UCSZ32 2
# define RXB83  1
# define TXB83  0

# define UCSR3C _SFR_MEM8(0x132)
# define UMSEL31 7
# define UMSEL30 6
# define UPM31  5
# define UPM30  4
# define USBS3  3
# define UCSZ31 2
# define UCSZ30 1
# define UCPOL3 0

/* Reserved [0x133] */

/* Combine UBRR3L and UBRR3H */
# define UBRR3  _SFR_MEM16(0x134)

# define UBRR3L _SFR_MEM8(0x134)
# define UBRR3H _SFR_MEM8(0x135)

# define UDR3   _SFR_MEM8(0X136)

#endif /* __ATmegaxx0__ */

/* Reserved [0x137..1FF] */

/* Interrupt vectors */
/* Vector 0 is the reset vector */
/* External Interrupt Request 0 */
#define INT0_vect_num		1
#define INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* External Interrupt Request 1 */
#define INT1_vect_num		2
#define INT1_vect			_VECTOR(2)
#define SIG_INTERRUPT1			_VECTOR(2)

/* External Interrupt Request 2 */
#define INT2_vect_num		3
#define INT2_vect			_VECTOR(3)
#define SIG_INTERRUPT2			_VECTOR(3)

/* External Interrupt Request 3 */
#define INT3_vect_num		4
#define INT3_vect			_VECTOR(4)
#define SIG_INTERRUPT3			_VECTOR(4)

/* External Interrupt Request 4 */
#define INT4_vect_num		5
#define INT4_vect			_VECTOR(5)
#define SIG_INTERRUPT4			_VECTOR(5)

/* External Interrupt Request 5 */
#define INT5_vect_num		6
#define INT5_vect			_VECTOR(6)
#define SIG_INTERRUPT5			_VECTOR(6)

/* External Interrupt Request 6 */
#define INT6_vect_num		7
#define INT6_vect			_VECTOR(7)
#define SIG_INTERRUPT6			_VECTOR(7)

/* External Interrupt Request 7 */
#define INT7_vect_num		8
#define INT7_vect			_VECTOR(8)
#define SIG_INTERRUPT7			_VECTOR(8)

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect_num		9
#define PCINT0_vect			_VECTOR(9)
#define SIG_PIN_CHANGE0			_VECTOR(9)

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect_num		10
#define PCINT1_vect			_VECTOR(10)
#define SIG_PIN_CHANGE1			_VECTOR(10)

#if defined(__ATmegaxx0__)
/* Pin Change Interrupt Request 2 */
#define PCINT2_vect_num		11
#define PCINT2_vect			_VECTOR(11)
#define SIG_PIN_CHANGE2			_VECTOR(11)

#endif /* __ATmegaxx0__ */

/* Watchdog Time-out Interrupt */
#define WDT_vect_num		12
#define WDT_vect			_VECTOR(12)
#define SIG_WATCHDOG_TIMEOUT		_VECTOR(12)

/* Timer/Counter2 Compare Match A */
#define TIMER2_COMPA_vect_num	13
#define TIMER2_COMPA_vect		_VECTOR(13)
#define SIG_OUTPUT_COMPARE2A		_VECTOR(13)

/* Timer/Counter2 Compare Match B */
#define TIMER2_COMPB_vect_num	14
#define TIMER2_COMPB_vect		_VECTOR(14)
#define SIG_OUTPUT_COMPARE2B		_VECTOR(14)

/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect_num		15
#define TIMER2_OVF_vect			_VECTOR(15)
#define SIG_OVERFLOW2			_VECTOR(15)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect_num	16
#define TIMER1_CAPT_vect		_VECTOR(16)
#define SIG_INPUT_CAPTURE1		_VECTOR(16)

/* Timer/Counter1 Compare Match A */
#define TIMER1_COMPA_vect_num	17
#define TIMER1_COMPA_vect		_VECTOR(17)
#define SIG_OUTPUT_COMPARE1A		_VECTOR(17)

/* Timer/Counter1 Compare Match B */
#define TIMER1_COMPB_vect_num	18
#define TIMER1_COMPB_vect		_VECTOR(18)
#define SIG_OUTPUT_COMPARE1B		_VECTOR(18)

/* Timer/Counter1 Compare Match C */
#define TIMER1_COMPC_vect_num	19
#define TIMER1_COMPC_vect		_VECTOR(19)
#define SIG_OUTPUT_COMPARE1C		_VECTOR(19)

/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect_num		20
#define TIMER1_OVF_vect			_VECTOR(20)
#define SIG_OVERFLOW1			_VECTOR(20)

/* Timer/Counter0 Compare Match A */
#define TIMER0_COMPA_vect_num	21
#define TIMER0_COMPA_vect		_VECTOR(21)
#define SIG_OUTPUT_COMPARE0A		_VECTOR(21)

/* Timer/Counter0 Compare Match B */
#define TIMER0_COMPB_vect_num	22
#define TIMER0_COMPB_vect		_VECTOR(22)
#define SIG_OUTPUT_COMPARE0B		_VECTOR(22)

/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect_num		23
#define TIMER0_OVF_vect			_VECTOR(23)
#define SIG_OVERFLOW0			_VECTOR(23)

/* SPI Serial Transfer Complete */
#define SPI_STC_vect_num		24
#define SPI_STC_vect			_VECTOR(24)
#define SIG_SPI				_VECTOR(24)

/* USART0, Rx Complete */
#define USART0_RX_vect_num		25
#define USART0_RX_vect			_VECTOR(25)
#define SIG_USART0_RECV			_VECTOR(25)

/* USART0 Data register Empty */
#define USART0_UDRE_vect_num	26
#define USART0_UDRE_vect		_VECTOR(26)
#define SIG_USART0_DATA			_VECTOR(26)

/* USART0, Tx Complete */
#define USART0_TX_vect_num		27
#define USART0_TX_vect			_VECTOR(27)
#define SIG_USART0_TRANS		_VECTOR(27)

/* Analog Comparator */
#define ANALOG_COMP_vect_num	28
#define ANALOG_COMP_vect		_VECTOR(28)
#define SIG_COMPARATOR			_VECTOR(28)

/* ADC Conversion Complete */
#define ADC_vect_num		29
#define ADC_vect			_VECTOR(29)
#define SIG_ADC				_VECTOR(29)

/* EEPROM Ready */
#define EE_READY_vect_num		30
#define EE_READY_vect			_VECTOR(30)
#define SIG_EEPROM_READY		_VECTOR(30)

/* Timer/Counter3 Capture Event */
#define TIMER3_CAPT_vect_num	31
#define TIMER3_CAPT_vect		_VECTOR(31)
#define SIG_INPUT_CAPTURE3		_VECTOR(31)

/* Timer/Counter3 Compare Match A */
#define TIMER3_COMPA_vect_num	32
#define TIMER3_COMPA_vect		_VECTOR(32)
#define SIG_OUTPUT_COMPARE3A		_VECTOR(32)

/* Timer/Counter3 Compare Match B */
#define TIMER3_COMPB_vect_num	33
#define TIMER3_COMPB_vect		_VECTOR(33)
#define SIG_OUTPUT_COMPARE3B		_VECTOR(33)

/* Timer/Counter3 Compare Match C */
#define TIMER3_COMPC_vect_num	34
#define TIMER3_COMPC_vect		_VECTOR(34)
#define SIG_OUTPUT_COMPARE3C		_VECTOR(34)

/* Timer/Counter3 Overflow */
#define TIMER3_OVF_vect_num		35
#define TIMER3_OVF_vect			_VECTOR(35)
#define SIG_OVERFLOW3			_VECTOR(35)

/* USART1, Rx Complete */
#define USART1_RX_vect_num		36
#define USART1_RX_vect			_VECTOR(36)
#define SIG_USART1_RECV			_VECTOR(36)

/* USART1 Data register Empty */
#define USART1_UDRE_vect_num	37
#define USART1_UDRE_vect		_VECTOR(37)
#define SIG_USART1_DATA			_VECTOR(37)

/* USART1, Tx Complete */
#define USART1_TX_vect_num		38
#define USART1_TX_vect			_VECTOR(38)
#define SIG_USART1_TRANS		_VECTOR(38)

/* 2-wire Serial Interface */
#define TWI_vect_num		39
#define TWI_vect			_VECTOR(39)
#define SIG_2WIRE_SERIAL		_VECTOR(39)

/* Store Program Memory Read */
#define SPM_READY_vect_num		40
#define SPM_READY_vect			_VECTOR(40)
#define SIG_SPM_READY			_VECTOR(40)

#if defined(__ATmegaxx0__)
/* Timer/Counter4 Capture Event */
#define TIMER4_CAPT_vect_num	41
#define TIMER4_CAPT_vect		_VECTOR(41)
#define SIG_INPUT_CAPTURE4		_VECTOR(41)

#endif /* __ATmegaxx0__ */

/* Timer/Counter4 Compare Match A */
#define TIMER4_COMPA_vect_num	42
#define TIMER4_COMPA_vect		_VECTOR(42)
#define SIG_OUTPUT_COMPARE4A		_VECTOR(42)

/* Timer/Counter4 Compare Match B */
#define TIMER4_COMPB_vect_num	43
#define TIMER4_COMPB_vect		_VECTOR(43)
#define SIG_OUTPUT_COMPARE4B		_VECTOR(43)

/* Timer/Counter4 Compare Match C */
#define TIMER4_COMPC_vect_num	44
#define TIMER4_COMPC_vect		_VECTOR(44)
#define SIG_OUTPUT_COMPARE4C		_VECTOR(44)

/* Timer/Counter4 Overflow */
#define TIMER4_OVF_vect_num		45
#define TIMER4_OVF_vect			_VECTOR(45)
#define SIG_OVERFLOW4			_VECTOR(45)

#if defined(__ATmegaxx0__)
/* Timer/Counter5 Capture Event */
#define TIMER5_CAPT_vect_num	46
#define TIMER5_CAPT_vect		_VECTOR(46)
#define SIG_INPUT_CAPTURE5		_VECTOR(46)

#endif /* __ATmegaxx0__ */

/* Timer/Counter5 Compare Match A */
#define TIMER5_COMPA_vect_num	47
#define TIMER5_COMPA_vect		_VECTOR(47)
#define SIG_OUTPUT_COMPARE5A		_VECTOR(47)

/* Timer/Counter5 Compare Match B */
#define TIMER5_COMPB_vect_num	48
#define TIMER5_COMPB_vect		_VECTOR(48)
#define SIG_OUTPUT_COMPARE5B		_VECTOR(48)

/* Timer/Counter5 Compare Match C */
#define TIMER5_COMPC_vect_num	49
#define TIMER5_COMPC_vect		_VECTOR(49)
#define SIG_OUTPUT_COMPARE5C		_VECTOR(49)

/* Timer/Counter5 Overflow */
#define TIMER5_OVF_vect_num		50
#define TIMER5_OVF_vect			_VECTOR(50)
#define SIG_OVERFLOW5			_VECTOR(50)

#if defined(__ATmegaxx1__)

# define _VECTORS_SIZE 204

#else

/* USART2, Rx Complete */
#define USART2_RX_vect_num		51
#define USART2_RX_vect			_VECTOR(51)
#define SIG_USART2_RECV			_VECTOR(51)

/* USART2 Data register Empty */
#define USART2_UDRE_vect_num		52
#define USART2_UDRE_vect		_VECTOR(52)
#define SIG_USART2_DATA			_VECTOR(52)

/* USART2, Tx Complete */
#define USART2_TX_vect_num		53
#define USART2_TX_vect			_VECTOR(53)
#define SIG_USART2_TRANS		_VECTOR(53)

/* USART3, Rx Complete */
#define USART3_RX_vect_num		54
#define USART3_RX_vect			_VECTOR(54)
#define SIG_USART3_RECV			_VECTOR(54)

/* USART3 Data register Empty */
#define USART3_UDRE_vect_num		55
#define USART3_UDRE_vect		_VECTOR(55)
#define SIG_USART3_DATA			_VECTOR(55)

/* USART3, Tx Complete */
#define USART3_TX_vect_num		56
#define USART3_TX_vect			_VECTOR(56)
#define SIG_USART3_TRANS		_VECTOR(56)

# define _VECTORS_SIZE 228

#endif /* __ATmegaxx1__ */

#if defined(__ATmegaxx0__)
# undef __ATmegaxx0__
#endif

#if defined(__ATmegaxx1__)
# undef __ATmegaxx1__
#endif


/* Deprecated items */
#if !defined(__AVR_LIBC_DEPRECATED_ENABLE__)

#pragma GCC system_header

#pragma GCC poison SIG_INTERRUPT0
#pragma GCC poison SIG_INTERRUPT1
#pragma GCC poison SIG_INTERRUPT2
#pragma GCC poison SIG_INTERRUPT3
#pragma GCC poison SIG_INTERRUPT4
#pragma GCC poison SIG_INTERRUPT5
#pragma GCC poison SIG_INTERRUPT6
#pragma GCC poison SIG_INTERRUPT7
#pragma GCC poison SIG_PIN_CHANGE0
#pragma GCC poison SIG_PIN_CHANGE1
#pragma GCC poison SIG_PIN_CHANGE2
#pragma GCC poison SIG_WATCHDOG_TIMEOUT
#pragma GCC poison SIG_OUTPUT_COMPARE2A
#pragma GCC poison SIG_OUTPUT_COMPARE2B
#pragma GCC poison SIG_OVERFLOW2
#pragma GCC poison SIG_INPUT_CAPTURE1
#pragma GCC poison SIG_OUTPUT_COMPARE1A
#pragma GCC poison SIG_OUTPUT_COMPARE1B
#pragma GCC poison SIG_OUTPUT_COMPARE1C
#pragma GCC poison SIG_OVERFLOW1
#pragma GCC poison SIG_OUTPUT_COMPARE0A
#pragma GCC poison SIG_OUTPUT_COMPARE0B
#pragma GCC poison SIG_OVERFLOW0
#pragma GCC poison SIG_SPI
#pragma GCC poison SIG_USART0_RECV
#pragma GCC poison SIG_USART0_DATA
#pragma GCC poison SIG_USART0_TRANS
#pragma GCC poison SIG_COMPARATOR
#pragma GCC poison SIG_ADC
#pragma GCC poison SIG_EEPROM_READY
#pragma GCC poison SIG_INPUT_CAPTURE3
#pragma GCC poison SIG_OUTPUT_COMPARE3A
#pragma GCC poison SIG_OUTPUT_COMPARE3B
#pragma GCC poison SIG_OUTPUT_COMPARE3C
#pragma GCC poison SIG_OVERFLOW3
#pragma GCC poison SIG_USART1_RECV
#pragma GCC poison SIG_USART1_DATA
#pragma GCC poison SIG_USART1_TRANS
#pragma GCC poison SIG_2WIRE_SERIAL
#pragma GCC poison SIG_SPM_READY
#pragma GCC poison SIG_INPUT_CAPTURE4
#pragma GCC poison SIG_OUTPUT_COMPARE4A
#pragma GCC poison SIG_OUTPUT_COMPARE4B
#pragma GCC poison SIG_OUTPUT_COMPARE4C
#pragma GCC poison SIG_OVERFLOW4
#pragma GCC poison SIG_INPUT_CAPTURE5
#pragma GCC poison SIG_OUTPUT_COMPARE5A
#pragma GCC poison SIG_OUTPUT_COMPARE5B
#pragma GCC poison SIG_OUTPUT_COMPARE5C
#pragma GCC poison SIG_OVERFLOW5
#pragma GCC poison SIG_USART2_RECV
#pragma GCC poison SIG_USART2_DATA
#pragma GCC poison SIG_USART2_TRANS
#pragma GCC poison SIG_USART3_RECV
#pragma GCC poison SIG_USART3_DATA
#pragma GCC poison SIG_USART3_TRANS

#endif  /* !defined(__AVR_LIBC_DEPRECATED_ENABLE__) */


#endif /* _AVR_IOMXX0_1_H_ */
