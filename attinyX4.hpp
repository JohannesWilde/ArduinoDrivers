#ifndef TMP_ATTINYX4_HPP
#define TMP_ATTINYX4_HPP

// ATMEL Attiny84
//                           +-\/-+
//                     VCC  1|    |14  GND
//             (D 10)  PB0  2|    |13  AREF (D  0)
//             (D  9)  PB1  3|    |12  PA1  (D  1) 
//                     PB3  4|    |11  PA2  (D  2) 
//  PWM  INT0  (D  8)  PB2  5|    |10  PA3  (D  3) 
//  PWM        (D  7)  PA7  6|    |9   PA4  (D  4) 
//  PWM        (D  6)  PA6  7|    |8   PA5  (D  5)        PWM
//                           +----+

#ifndef _AVR_IOTNX4_H_
#warning "This struct is for an AttinyX4 - so for any real-world scenario this should also be #defined."
#endif

#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

struct ATtinyX4
{
public:
    // you can access these registers - but only do so if using the higher level AvrIoRegister or even AvrPin
    // is really not sufficient.

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTA_REGISTER>::address, uint8_t> PortAInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINA_REGISTER>::address, uint8_t> PinAInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRA_REGISTER>::address, uint8_t> DdrAInternal;
    typedef AvrIoRegister<PortAInternal, DdrAInternal, PinAInternal> RegisterA;
    typedef AvrPin<RegisterA, PORTA0> pinA0;
    typedef AvrPin<RegisterA, PORTA1> pinA1;
    typedef AvrPin<RegisterA, PORTA2> pinA2;
    typedef AvrPin<RegisterA, PORTA3> pinA3;
    typedef AvrPin<RegisterA, PORTA4> pinA4;
    typedef AvrPin<RegisterA, PORTA5> pinA5;
    typedef AvrPin<RegisterA, PORTA6> pinA6;
    typedef AvrPin<RegisterA, PORTA7> pinA7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    typedef AvrIoRegister<PortBInternal, DdrBInternal, PinBInternal> RegisterB;
    typedef AvrPin<RegisterB, PORTB0> pinB0;
    typedef AvrPin<RegisterB, PORTB1> pinB1;
    typedef AvrPin<RegisterB, PORTB2> pinB2;
    typedef AvrPin<RegisterB, PORTB3> pinB3;
};

#endif // TMP_ATTINYX4_HPP
