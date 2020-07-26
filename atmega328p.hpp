#ifndef TMP_ATMEGA328P_HPP
#define TMP_ATMEGA328P_HPP

// ATMEL ATMEGA328p
//
//                  +-\/-+
// Reset      PC6  1|    |28  PC5
//            PD0  2|    |27  PC4
//            PD1  3|    |26  PC3
//            PD2  4|    |25  PC2
// PWM+       PD3  5|    |24  PC1
//            PD4  6|    |23  PC0
//            VCC  7|    |22  GND
//            GND  8|    |21  AREF
//            PB6  9|    |20  AVCC
//            PB7 10|    |19  PB5
// PWM+       PD5 11|    |18  PB4
// PWM+       PD6 12|    |17  PB3  PWM
//            PD7 13|    |16  PB2  PWM
//            PB0 14|    |15  PB1  PWM
//                  +----+

#ifndef __AVR_ATmega328P__
#warning "This struct is for an Atmega328p - so for any real-world scenario this should also be #defined."
#endif

#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

struct Atmega328p
{
public:
    // you can access these registers - but only do so if using the higher level AvrIoRegister or even AvrPin
    // is really not sufficient.

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    typedef AvrIoRegister<PortBInternal, DdrBInternal, PinBInternal> RegisterB;
    typedef AvrPin<RegisterB, PORTB0> pinB0;
    typedef AvrPin<RegisterB, PORTB1> pinB1;
    typedef AvrPin<RegisterB, PORTB2> pinB2;
    typedef AvrPin<RegisterB, PORTB3> pinB3;
    typedef AvrPin<RegisterB, PORTB4> pinB4;
    typedef AvrPin<RegisterB, PORTB5> pinB5;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTC_REGISTER>::address, uint8_t> PortCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINC_REGISTER>::address, uint8_t> PinCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRC_REGISTER>::address, uint8_t> DdrCInternal;
    typedef AvrIoRegister<PortCInternal, DdrCInternal, PinCInternal> RegisterC;
    typedef AvrPin<RegisterC, PORTC0> pinC0;
    typedef AvrPin<RegisterC, PORTC1> pinC1;
    typedef AvrPin<RegisterC, PORTC2> pinC2;
    typedef AvrPin<RegisterC, PORTC3> pinC3;
    typedef AvrPin<RegisterC, PORTC4> pinC4;
    typedef AvrPin<RegisterC, PORTC5> pinC5;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTD_REGISTER>::address, uint8_t> PortDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PIND_REGISTER>::address, uint8_t> PinDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRD_REGISTER>::address, uint8_t> DdrDInternal;
    typedef AvrIoRegister<PortDInternal, DdrDInternal, PinDInternal> RegisterD;
    typedef AvrPin<RegisterD, PORTD0> pinD0;
    typedef AvrPin<RegisterD, PORTD1> pinD1;
    typedef AvrPin<RegisterD, PORTD2> pinD2;
    typedef AvrPin<RegisterD, PORTD3> pinD3;
    typedef AvrPin<RegisterD, PORTD4> pinD4;
    typedef AvrPin<RegisterD, PORTD5> pinD5;
    typedef AvrPin<RegisterD, PORTD6> pinD6;
    typedef AvrPin<RegisterD, PORTD7> pinD7;
};

#endif // TMP_ATMEGA328P_HPP
