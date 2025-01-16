/* Copyright (c) 2005,2007 Anatoly Sokolov
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

/* $Id: iotnx4.h 2225 2011-03-02 16:27:26Z arcanum $ */

/* avr/iotnx4.h - definitions for ATtiny24, ATtiny44 and ATtiny84 */

#ifndef _AVR_IOTNX4_H_
#define _AVR_IOTNX4_H_ 1

/* This file should only be included from <avr/io.h>, never directly. */

#ifndef _AVR_IO_H_
#  error "Include <avr/io.h> instead of this file."
#endif

#ifndef _AVR_IOXXX_H_
#  define _AVR_IOXXX_H_ "iotnx4.h"
#else
#  error "Attempt to include more than one <avr/ioXXX.h> file."
#endif 

/* I/O registers */

#define PRR     _SFR_IO8 (0x00)
#define PRTIM1  3
#define PRTIM0  2
#define PRUSI   1
#define PRADC   0

#define __AVR_HAVE_PRR	((1<<PRADC)|(1<<PRUSI)|(1<<PRTIM0)|(1<<PRTIM1))
#define __AVR_HAVE_PRR_PRADC
#define __AVR_HAVE_PRR_PRUSI
#define __AVR_HAVE_PRR_PRTIM0
#define __AVR_HAVE_PRR_PRTIM1

#define DIDR0_REGISTER 0x01
#define DIDR0_TYPE uint8_t
#define DIDR0_ACCESS _SFR_IO8
#define DIDR0 DIDR0_ACCESS(DIDR0_REGISTER)
#define ADC7D   7
#define ADC6D   6
#define ADC5D   5
#define ADC4D   4
#define ADC3D   3
#define ADC2D   2
#define ADC1D   1 
#define ADC0D   0

/* Reserved [0x02] */

#define ADCSRB  _SFR_IO8 (0x03)
#define BIN     7
#define ACME    6
#define ADLAR   4
#define ADTS2   2
#define ADTS1   1
#define ADTS0   0

#ifndef __ASSEMBLER__
#define ADC_REGISTER 0x04
#define ADC_TYPE uint16_t
#define ADC_ACCESS _SFR_IO16
#define ADC ADC_ACCESS(ADC_REGISTER)
#endif
#define ADCW_REGISTER 0x04
#define ADCW_TYPE uint16_t
#define ADCW_ACCESS _SFR_IO16
#define ADCW ADCW_ACCESS(ADCW_REGISTER)
#define ADCL_REGISTER 0x04
#define ADCL_TYPE uint8_t
#define ADCL_ACCESS _SFR_IO8
#define ADCL ADCL_ACCESS(ADCL_REGISTER)
#define ADCH_REGISTER 0x05
#define ADCH_TYPE uint8_t
#define ADCH_ACCESS _SFR_IO8
#define ADCH ADCH_ACCESS(ADCH_REGISTER)

#define ADCSRA  _SFR_IO8 (0x06)
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

#define ADMUX_REGISTER 0x07
#define ADMUX_TYPE uint8_t
#define ADMUX_ACCESS _SFR_IO8
#define ADMUX ADMUX_ACCESS(ADMUX_REGISTER)
#define REFS1   7
#define REFS0   6
#define MUX5    5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ACSR_REGISTER 0x08
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

/* Reserved [0x09..0x0A] */

#define TIFR1_REGISTER 0x0B
#define TIFR1_TYPE uint8_t
#define TIFR1_ACCESS _SFR_IO8
#define TIFR1 TIFR1_ACCESS(TIFR1_REGISTER)
#define ICF1    5
#define OCF1B   2
#define OCF1A   1
#define TOV1    0

#define TIMSK1_REGISTER 0x0C
#define TIMSK1_TYPE uint8_t
#define TIMSK1_ACCESS _SFR_IO8
#define TIMSK1 TIMSK1_ACCESS(TIMSK1_REGISTER)
#define ICIE1   5
#define OCIE1B  2
#define OCIE1A  1
#define TOIE1   0

#define USICR_REGISTER 0x0D
#define USICR_TYPE uint8_t
#define USICR_ACCESS _SFR_IO8
#define USICR USICR_ACCESS(USICR_REGISTER)
#define USISIE  7
#define USIOIE  6
#define USIWM1  5
#define USIWM0  4
#define USICS1  3
#define USICS0  2
#define USICLK  1
#define USITC   0

#define USISR_REGISTER 0x0E
#define USISR_TYPE uint8_t
#define USISR_ACCESS _SFR_IO8
#define USISR USISR_ACCESS(USISR_REGISTER)
#define USISIF  7 
#define USIOIF  6
#define USIPF   5
#define USIDC   4
#define USICNT3 3
#define USICNT2 2
#define USICNT1 1
#define USICNT0 0

#define USIDR_REGISTER 0x0F
#define USIDR_TYPE uint8_t
#define USIDR_ACCESS _SFR_IO8
#define USIDR USIDR_ACCESS(USIDR_REGISTER)

#define USIBR_REGISTER 0x10
#define USIBR_TYPE uint8_t
#define USIBR_ACCESS _SFR_IO8
#define USIBR USIBR_ACCESS(USIBR_REGISTER)

/* Reserved [0x11] */

#define PCMSK0_REGISTER 0x12
#define PCMSK0_TYPE uint8_t
#define PCMSK0_ACCESS _SFR_IO8
#define PCMSK0 PCMSK0_ACCESS(PCMSK0_REGISTER)
#define PCINT7  7
#define PCINT6  6
#define PCINT5  5
#define PCINT4  4
#define PCINT3  3
#define PCINT2  2
#define PCINT1  1
#define PCINT0  0

#define GPIOR0_REGISTER 0x13
#define GPIOR0_TYPE uint8_t
#define GPIOR0_ACCESS _SFR_IO8
#define GPIOR0 GPIOR0_ACCESS(GPIOR0_REGISTER)

#define GPIOR1_REGISTER 0x14
#define GPIOR1_TYPE uint8_t
#define GPIOR1_ACCESS _SFR_IO8
#define GPIOR1 GPIOR1_ACCESS(GPIOR1_REGISTER)

#define GPIOR2_REGISTER 0x15
#define GPIOR2_TYPE uint8_t
#define GPIOR2_ACCESS _SFR_IO8
#define GPIOR2 GPIOR2_ACCESS(GPIOR2_REGISTER)

#define PINB_REGISTER 0x16
#define PINB_TYPE uint8_t
#define PINB_ACCESS _SFR_IO8
#define PINB PINB_ACCESS(PINB_REGISTER)
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

#define DDRB_REGISTER 0x17
#define DDRB_TYPE uint8_t
#define DDRB_ACCESS _SFR_IO8
#define DDRB DDRB_ACCESS(DDRB_REGISTER)
#define DDB3    3
#define DDB2    2
#define DDB1    1
#define DDB0    0

#define PORTB_REGISTER 0x18
#define PORTB_TYPE uint8_t
#define PORTB_ACCESS _SFR_IO8
#define PORTB PORTB_ACCESS(PORTB_REGISTER)
#define PB3     3
#define PB2     2
#define PB1     1
#define PB0     0

#define PINA_REGISTER 0x19
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

#define DDRA_REGISTER 0x1A
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

#define PORTA_REGISTER 0x1B
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

/* EEPROM Control Register EECR */
#define EECR_REGISTER 0x1C
#define EECR_TYPE uint8_t
#define EECR_ACCESS _SFR_IO8
#define EECR EECR_ACCESS(EECR_REGISTER)
#define EEPM1   5
#define EEPM0   4
#define EERIE   3
#define EEMPE   2
#define EEPE    1
#define EERE    0

/* EEPROM Data Register */
#define EEDR_REGISTER 0x1D
#define EEDR_TYPE uint8_t
#define EEDR_ACCESS _SFR_IO8
#define EEDR EEDR_ACCESS(EEDR_REGISTER)

/* EEPROM Address Register */
#define EEAR_REGISTER 0x1E
#define EEAR_TYPE uint16_t
#define EEAR_ACCESS _SFR_IO16
#define EEAR EEAR_ACCESS(EEAR_REGISTER)
#define EEARL_REGISTER 0x1E
#define EEARL_TYPE uint8_t
#define EEARL_ACCESS _SFR_IO8
#define EEARL EEARL_ACCESS(EEARL_REGISTER)
#define EEARH_REGISTER 0x1F
#define EEARH_TYPE uint8_t
#define EEARH_ACCESS _SFR_IO8
#define EEARH EEARH_ACCESS(EEARH_REGISTER)

#define PCMSK1_REGISTER 0x20
#define PCMSK1_TYPE uint8_t
#define PCMSK1_ACCESS _SFR_IO8
#define PCMSK1 PCMSK1_ACCESS(PCMSK1_REGISTER)
#define PCINT11 3
#define PCINT10 2
#define PCINT9  1
#define PCINT8  0

#define WDTCSR_REGISTER 0x21
#define WDTCSR_TYPE uint8_t
#define WDTCSR_ACCESS _SFR_IO8
#define WDTCSR WDTCSR_ACCESS(WDTCSR_REGISTER)
#define WDIF    7
#define WDIE    6
#define WDP3    5
#define WDCE    4
#define WDE     3
#define WDP2    2
#define WDP1    1
#define WDP0    0

#define TCCR1C_REGISTER 0x22
#define TCCR1C_TYPE uint8_t
#define TCCR1C_ACCESS _SFR_IO8
#define TCCR1C TCCR1C_ACCESS(TCCR1C_REGISTER)
#define FOC1A   7
#define FOC1B   6

#define GTCCR_REGISTER 0x23
#define GTCCR_TYPE uint8_t
#define GTCCR_ACCESS _SFR_IO8
#define GTCCR GTCCR_ACCESS(GTCCR_REGISTER)
#define TSM     7
#define PSR10   0

#define ICR1_REGISTER 0x24
#define ICR1_TYPE uint16_t
#define ICR1_ACCESS _SFR_IO16
#define ICR1 ICR1_ACCESS(ICR1_REGISTER)
#define ICR1L_REGISTER 0x24
#define ICR1L_TYPE uint8_t
#define ICR1L_ACCESS _SFR_IO8
#define ICR1L ICR1L_ACCESS(ICR1L_REGISTER)
#define ICR1H_REGISTER 0x25
#define ICR1H_TYPE uint8_t
#define ICR1H_ACCESS _SFR_IO8
#define ICR1H ICR1H_ACCESS(ICR1H_REGISTER)

#define CLKPR_REGISTER 0x26
#define CLKPR_TYPE uint8_t
#define CLKPR_ACCESS _SFR_IO8
#define CLKPR CLKPR_ACCESS(CLKPR_REGISTER)
#define CLKPCE  7
#define CLKPS3  3
#define CLKPS2  2
#define CLKPS1  1
#define CLKPS0  0

#define DWDR_REGISTER 0x27
#define DWDR_TYPE uint8_t
#define DWDR_ACCESS _SFR_IO8
#define DWDR DWDR_ACCESS(DWDR_REGISTER)

#define OCR1B_REGISTER 0x28
#define OCR1B_TYPE uint16_t
#define OCR1B_ACCESS _SFR_IO16
#define OCR1B OCR1B_ACCESS(OCR1B_REGISTER)
#define OCR1BL_REGISTER 0x28
#define OCR1BL_TYPE uint8_t
#define OCR1BL_ACCESS _SFR_IO8
#define OCR1BL OCR1BL_ACCESS(OCR1BL_REGISTER)
#define OCR1BH_REGISTER 0x29
#define OCR1BH_TYPE uint8_t
#define OCR1BH_ACCESS _SFR_IO8
#define OCR1BH OCR1BH_ACCESS(OCR1BH_REGISTER)

#define OCR1A_REGISTER 0x2A
#define OCR1A_TYPE uint16_t
#define OCR1A_ACCESS _SFR_IO16
#define OCR1A OCR1A_ACCESS(OCR1A_REGISTER)
#define OCR1AL_REGISTER 0x2A
#define OCR1AL_TYPE uint8_t
#define OCR1AL_ACCESS _SFR_IO8
#define OCR1AL OCR1AL_ACCESS(OCR1AL_REGISTER)
#define OCR1AH_REGISTER 0x2B
#define OCR1AH_TYPE uint8_t
#define OCR1AH_ACCESS _SFR_IO8
#define OCR1AH OCR1AH_ACCESS(OCR1AH_REGISTER)

/* keep misspelled names from avr-libc 1.4.[0..1] for compatibility */
#define OCRB1_REGISTER 0x28
#define OCRB1_TYPE uint16_t
#define OCRB1_ACCESS _SFR_IO16
#define OCRB1 OCRB1_ACCESS(OCRB1_REGISTER)
#define OCRB1L_REGISTER 0x28
#define OCRB1L_TYPE uint8_t
#define OCRB1L_ACCESS _SFR_IO8
#define OCRB1L OCRB1L_ACCESS(OCRB1L_REGISTER)
#define OCRB1H_REGISTER 0x29
#define OCRB1H_TYPE uint8_t
#define OCRB1H_ACCESS _SFR_IO8
#define OCRB1H OCRB1H_ACCESS(OCRB1H_REGISTER)

#define OCRA1_REGISTER 0x2A
#define OCRA1_TYPE uint16_t
#define OCRA1_ACCESS _SFR_IO16
#define OCRA1 OCRA1_ACCESS(OCRA1_REGISTER)
#define OCRA1L_REGISTER 0x2A
#define OCRA1L_TYPE uint8_t
#define OCRA1L_ACCESS _SFR_IO8
#define OCRA1L OCRA1L_ACCESS(OCRA1L_REGISTER)
#define OCRA1H_REGISTER 0x2B
#define OCRA1H_TYPE uint8_t
#define OCRA1H_ACCESS _SFR_IO8
#define OCRA1H OCRA1H_ACCESS(OCRA1H_REGISTER)

#define TCNT1_REGISTER 0x2C
#define TCNT1_TYPE uint16_t
#define TCNT1_ACCESS _SFR_IO16
#define TCNT1 TCNT1_ACCESS(TCNT1_REGISTER)
#define TCNT1L_REGISTER 0x2C
#define TCNT1L_TYPE uint8_t
#define TCNT1L_ACCESS _SFR_IO8
#define TCNT1L TCNT1L_ACCESS(TCNT1L_REGISTER)
#define TCNT1H_REGISTER 0x2D
#define TCNT1H_TYPE uint8_t
#define TCNT1H_ACCESS _SFR_IO8
#define TCNT1H TCNT1H_ACCESS(TCNT1H_REGISTER)

#define TCCR1B_REGISTER 0x2E
#define TCCR1B_TYPE uint8_t
#define TCCR1B_ACCESS _SFR_IO8
#define TCCR1B TCCR1B_ACCESS(TCCR1B_REGISTER)
#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCCR1A_REGISTER 0x2F
#define TCCR1A_TYPE uint8_t
#define TCCR1A_ACCESS _SFR_IO8
#define TCCR1A TCCR1A_ACCESS(TCCR1A_REGISTER)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define WGM11   1
#define WGM10   0

#define TCCR0A_REGISTER 0x30
#define TCCR0A_TYPE uint8_t
#define TCCR0A_ACCESS _SFR_IO8
#define TCCR0A TCCR0A_ACCESS(TCCR0A_REGISTER)
#define COM0A1  7
#define COM0A0  6
#define COM0B1  5
#define COM0B0  4
#define WGM01   1
#define WGM00   0

#define OSCCAL_REGISTER 0x31
#define OSCCAL_TYPE uint8_t
#define OSCCAL_ACCESS _SFR_IO8
#define OSCCAL OSCCAL_ACCESS(OSCCAL_REGISTER)

#define TCNT0_REGISTER 0x32
#define TCNT0_TYPE uint8_t
#define TCNT0_ACCESS _SFR_IO8
#define TCNT0 TCNT0_ACCESS(TCNT0_REGISTER)

#define TCCR0B_REGISTER 0x33
#define TCCR0B_TYPE uint8_t
#define TCCR0B_ACCESS _SFR_IO8
#define TCCR0B TCCR0B_ACCESS(TCCR0B_REGISTER)
#define FOC0A   7
#define FOC0B   6
#define WGM02   3
#define CS02    2
#define CS01    1
#define CS00    0

#define MCUSR_REGISTER 0x34
#define MCUSR_TYPE uint8_t
#define MCUSR_ACCESS _SFR_IO8
#define MCUSR MCUSR_ACCESS(MCUSR_REGISTER)
#define WDRF    3
#define BORF    2
#define EXTRF   1
#define PORF    0

#define MCUCR_REGISTER 0x35
#define MCUCR_TYPE uint8_t
#define MCUCR_ACCESS _SFR_IO8
#define MCUCR MCUCR_ACCESS(MCUCR_REGISTER)
#define BODS    7
#define PUD     6
#define SE      5
#define SM1     4
#define SM0     3
#define BODSE   2
#define ISC01   1
#define ISC00   0

#define OCR0A_REGISTER 0x36
#define OCR0A_TYPE uint8_t
#define OCR0A_ACCESS _SFR_IO8
#define OCR0A OCR0A_ACCESS(OCR0A_REGISTER)

#define SPMCSR_REGISTER 0x37
#define SPMCSR_TYPE uint8_t
#define SPMCSR_ACCESS _SFR_IO8
#define SPMCSR SPMCSR_ACCESS(SPMCSR_REGISTER)
#define RSIG    5
#define CTPB    4
#define RFLB    3
#define PGWRT   2
#define PGERS   1
#define SPMEN   0

#define TIFR0_REGISTER 0x38
#define TIFR0_TYPE uint8_t
#define TIFR0_ACCESS _SFR_IO8
#define TIFR0 TIFR0_ACCESS(TIFR0_REGISTER)
#define OCF0B   2
#define OCF0A   1
#define TOV0    0

#define TIMSK0_REGISTER 0x39
#define TIMSK0_TYPE uint8_t
#define TIMSK0_ACCESS _SFR_IO8
#define TIMSK0 TIMSK0_ACCESS(TIMSK0_REGISTER)
#define OCIE0B  2
#define OCIE0A  1
#define TOIE0   0

#define GIFR_REGISTER 0x3A
#define GIFR_TYPE uint8_t
#define GIFR_ACCESS _SFR_IO8
#define GIFR GIFR_ACCESS(GIFR_REGISTER)
#define INTF0   6
#define PCIF1   5
#define PCIF0   4

#define GIMSK_REGISTER 0x3B
#define GIMSK_TYPE uint8_t
#define GIMSK_ACCESS _SFR_IO8
#define GIMSK GIMSK_ACCESS(GIMSK_REGISTER)
#define INT0    6
#define PCIE1   5
#define PCIE0   4

#define OCR0B_REGISTER 0x3C
#define OCR0B_TYPE uint8_t
#define OCR0B_ACCESS _SFR_IO8
#define OCR0B OCR0B_ACCESS(OCR0B_REGISTER)

/* 0x3D..0x3E SP  [defined in <avr/io.h>] */
/* 0x3F SREG      [defined in <avr/io.h>] */

///---

/* Interrupt vectors */
/* Interrupt vector 0 is the reset vector. */
/* External Interrupt Request 0 */
#define INT0_vect_num		    1
#define INT0_vect			    _VECTOR(1)
#define EXT_INT0_vect_num    	1
#define EXT_INT0_vect			_VECTOR(1)
#define SIG_INTERRUPT0			_VECTOR(1)

/* Pin Change Interrupt Request 0 */
#define PCINT0_vect_num		    2
#define PCINT0_vect			    _VECTOR(2)
#define SIG_PIN_CHANGE0			_VECTOR(2)

/* Pin Change Interrupt Request 1 */
#define PCINT1_vect_num		    3
#define PCINT1_vect			    _VECTOR(3)
#define SIG_PIN_CHANGE1			_VECTOR(3)

/* Watchdog Time-out */
#define WDT_vect_num			4
#define WDT_vect			    _VECTOR(4)
#define WATCHDOG_vect_num		4
#define WATCHDOG_vect			_VECTOR(4)
#define SIG_WATCHDOG_TIMEOUT	_VECTOR(4)

/* Timer/Counter1 Capture Event */
#define TIMER1_CAPT_vect_num	5
#define TIMER1_CAPT_vect		_VECTOR(5)
#define TIM1_CAPT_vect_num		5
#define TIM1_CAPT_vect			_VECTOR(5)
#define SIG_INPUT_CAPTURE1		_VECTOR(5)

/* Timer/Counter1 Compare Match A */
#define TIM1_COMPA_vect_num		6
#define TIM1_COMPA_vect			_VECTOR(6)
#define SIG_OUTPUT_COMPARE1A	_VECTOR(6)

/* Timer/Counter1 Compare Match B */
#define TIM1_COMPB_vect_num		7
#define TIM1_COMPB_vect			_VECTOR(7)
#define SIG_OUTPUT_COMPARE1B	_VECTOR(7)

/* Timer/Counter1 Overflow */
#define TIM1_OVF_vect_num		8
#define TIM1_OVF_vect			_VECTOR(8)
#define SIG_OVERFLOW1			_VECTOR(8)

/* Timer/Counter0 Compare Match A */
#define TIM0_COMPA_vect_num		9
#define TIM0_COMPA_vect			_VECTOR(9)
#define SIG_OUTPUT_COMPARE0A	_VECTOR(9)

/* Timer/Counter0 Compare Match B */
#define TIM0_COMPB_vect_num		10
#define TIM0_COMPB_vect			_VECTOR(10)
#define SIG_OUTPUT_COMPARE0B	_VECTOR(10)

/* Timer/Counter0 Overflow */
#define TIM0_OVF_vect_num		11
#define TIM0_OVF_vect			_VECTOR(11)
#define SIG_OVERFLOW0			_VECTOR(11)

/* Analog Comparator */
#define ANA_COMP_vect_num		12
#define ANA_COMP_vect			_VECTOR(12)
#define SIG_COMPARATOR			_VECTOR(12)

/* ADC Conversion Complete */
#define ADC_vect_num		    13
#define ADC_vect			    _VECTOR(13)
#define SIG_ADC				    _VECTOR(13)

/* EEPROM Ready */
#define EE_RDY_vect_num		    14
#define EE_RDY_vect			    _VECTOR(14)
#define SIG_EEPROM_READY		_VECTOR(14)

/* USI START */
#define USI_START_vect_num		15
#define USI_START_vect			_VECTOR(15)
#define USI_STR_vect_num		15
#define USI_STR_vect			_VECTOR(15)
#define SIG_USI_START			_VECTOR(15)

/* USI Overflow */
#define USI_OVF_vect_num		16
#define USI_OVF_vect			_VECTOR(16)
#define SIG_USI_OVERFLOW		_VECTOR(16)

#define _VECTORS_SIZE 34

#endif /* _AVR_IOTNX4_H_ */
