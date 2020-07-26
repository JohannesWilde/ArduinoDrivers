#ifndef TMP_ATMEG2560_HPP
#define TMP_ATMEG2560_HPP

// ATMEL ATMEGA2560

#ifndef __AVR_ATmega2560__
#warning "This struct is for an Atmega2560 - so for any real-world scenario this should also be #defined."
#endif

#include "avrinternalregister.hpp"
#include "avrioregister.hpp"
#include "avrpin.hpp"

struct Atmega2560
{
public:
    // you can access these registers - but only do so if using the higher level AvrIoRegister or even AvrPin
    // is really not sufficient./home/user/PycharmProjects/TestProject/venv/bin/python /home/user/QtProjects/RGBWLighting/libraries/ArduinoDrivers/avrSrc/avrHeaderConverter.py

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
    typedef AvrPin<RegisterB, PORTB4> pinB4;
    typedef AvrPin<RegisterB, PORTB5> pinB5;
    typedef AvrPin<RegisterB, PORTB6> pinB6;
    typedef AvrPin<RegisterB, PORTB7> pinB7;

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
    typedef AvrPin<RegisterC, PORTC6> pinC6;
    typedef AvrPin<RegisterC, PORTC7> pinC7;

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

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTE_REGISTER>::address, uint8_t> PortEInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINE_REGISTER>::address, uint8_t> PinEInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRE_REGISTER>::address, uint8_t> DdrEInternal;
    typedef AvrIoRegister<PortEInternal, DdrEInternal, PinEInternal> RegisterE;
    typedef AvrPin<RegisterE, PORTE0> pinE0;
    typedef AvrPin<RegisterE, PORTE1> pinE1;
    typedef AvrPin<RegisterE, PORTE2> pinE2;
    typedef AvrPin<RegisterE, PORTE3> pinE3;
    typedef AvrPin<RegisterE, PORTE4> pinE4;
    typedef AvrPin<RegisterE, PORTE5> pinE5;
    typedef AvrPin<RegisterE, PORTE6> pinE6;
    typedef AvrPin<RegisterE, PORTE7> pinE7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTF_REGISTER>::address, uint8_t> PortFInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINF_REGISTER>::address, uint8_t> PinFInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRF_REGISTER>::address, uint8_t> DdrFInternal;
    typedef AvrIoRegister<PortFInternal, DdrFInternal, PinFInternal> RegisterF;
    typedef AvrPin<RegisterF, PORTF0> pinF0;
    typedef AvrPin<RegisterF, PORTF1> pinF1;
    typedef AvrPin<RegisterF, PORTF2> pinF2;
    typedef AvrPin<RegisterF, PORTF3> pinF3;
    typedef AvrPin<RegisterF, PORTF4> pinF4;
    typedef AvrPin<RegisterF, PORTF5> pinF5;
    typedef AvrPin<RegisterF, PORTF6> pinF6;
    typedef AvrPin<RegisterF, PORTF7> pinF7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTG_REGISTER>::address, uint8_t> PortGInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PING_REGISTER>::address, uint8_t> PinGInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRG_REGISTER>::address, uint8_t> DdrGInternal;
    typedef AvrIoRegister<PortGInternal, DdrGInternal, PinGInternal> RegisterG;
    typedef AvrPin<RegisterG, PORTG0> pinG0;
    typedef AvrPin<RegisterG, PORTG1> pinG1;
    typedef AvrPin<RegisterG, PORTG2> pinG2;
    typedef AvrPin<RegisterG, PORTG3> pinG3;
    typedef AvrPin<RegisterG, PORTG4> pinG4;
    typedef AvrPin<RegisterG, PORTG5> pinG5;
    // No access to G6 and G7

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTH_REGISTER>::address, uint8_t> PortHInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINH_REGISTER>::address, uint8_t> PinHInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRH_REGISTER>::address, uint8_t> DdrHInternal;
    typedef AvrIoRegister<PortHInternal, DdrHInternal, PinHInternal> RegisterH;
    typedef AvrPin<RegisterH, PORTH0> pinH0;
    typedef AvrPin<RegisterH, PORTH1> pinH1;
    typedef AvrPin<RegisterH, PORTH2> pinH2;
    typedef AvrPin<RegisterH, PORTH3> pinH3;
    typedef AvrPin<RegisterH, PORTH4> pinH4;
    typedef AvrPin<RegisterH, PORTH5> pinH5;
    typedef AvrPin<RegisterH, PORTH6> pinH6;
    typedef AvrPin<RegisterH, PORTH7> pinH7;

    // no I-Register

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTJ_REGISTER>::address, uint8_t> PortJInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINJ_REGISTER>::address, uint8_t> PinJInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRJ_REGISTER>::address, uint8_t> DdrJInternal;
    typedef AvrIoRegister<PortJInternal, DdrJInternal, PinJInternal> RegisterJ;
    typedef AvrPin<RegisterJ, PORTJ0> pinJ0;
    typedef AvrPin<RegisterJ, PORTJ1> pinJ1;
    typedef AvrPin<RegisterJ, PORTJ2> pinJ2;
    typedef AvrPin<RegisterJ, PORTJ3> pinJ3;
    typedef AvrPin<RegisterJ, PORTJ4> pinJ4;
    typedef AvrPin<RegisterJ, PORTJ5> pinJ5;
    typedef AvrPin<RegisterJ, PORTJ6> pinJ6;
    typedef AvrPin<RegisterJ, PORTJ7> pinJ7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTK_REGISTER>::address, uint8_t> PortKInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINK_REGISTER>::address, uint8_t> PinKInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRK_REGISTER>::address, uint8_t> DdrKInternal;
    typedef AvrIoRegister<PortKInternal, DdrKInternal, PinKInternal> RegisterK;
    typedef AvrPin<RegisterK, PORTK0> pinK0;
    typedef AvrPin<RegisterK, PORTK1> pinK1;
    typedef AvrPin<RegisterK, PORTK2> pinK2;
    typedef AvrPin<RegisterK, PORTK3> pinK3;
    typedef AvrPin<RegisterK, PORTK4> pinK4;
    typedef AvrPin<RegisterK, PORTK5> pinK5;
    typedef AvrPin<RegisterK, PORTK6> pinK6;
    typedef AvrPin<RegisterK, PORTK7> pinK7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTL_REGISTER>::address, uint8_t> PortLInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINL_REGISTER>::address, uint8_t> PinLInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRL_REGISTER>::address, uint8_t> DdrLInternal;
    typedef AvrIoRegister<PortLInternal, DdrLInternal, PinLInternal> RegisterL;
    typedef AvrPin<RegisterL, PORTL0> pinL0;
    typedef AvrPin<RegisterL, PORTL1> pinL1;
    typedef AvrPin<RegisterL, PORTL2> pinL2;
    typedef AvrPin<RegisterL, PORTL3> pinL3;
    typedef AvrPin<RegisterL, PORTL4> pinL4;
    typedef AvrPin<RegisterL, PORTL5> pinL5;
    typedef AvrPin<RegisterL, PORTL6> pinL6;
    typedef AvrPin<RegisterL, PORTL7> pinL7;
};

#endif // TMP_ATMEG2560_HPP
