#ifndef ATMEG2560_HPP
#define ATMEGA328P_HPP

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
    typedef AvrPin<RegisterA, PORTA0> A0;
    typedef AvrPin<RegisterA, PORTA1> A1;
    typedef AvrPin<RegisterA, PORTA2> A2;
    typedef AvrPin<RegisterA, PORTA3> A3;
    typedef AvrPin<RegisterA, PORTA4> A4;
    typedef AvrPin<RegisterA, PORTA5> A5;
    typedef AvrPin<RegisterA, PORTA6> A6;
    typedef AvrPin<RegisterA, PORTA7> A7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTB_REGISTER>::address, uint8_t> PortBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINB_REGISTER>::address, uint8_t> PinBInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRB_REGISTER>::address, uint8_t> DdrBInternal;
    typedef AvrIoRegister<PortBInternal, DdrBInternal, PinBInternal> RegisterB;
    typedef AvrPin<RegisterB, PORTB0> B0;
    typedef AvrPin<RegisterB, PORTB1> B1;
    typedef AvrPin<RegisterB, PORTB2> B2;
    typedef AvrPin<RegisterB, PORTB3> B3;
    typedef AvrPin<RegisterB, PORTB4> B4;
    typedef AvrPin<RegisterB, PORTB5> B5;
    typedef AvrPin<RegisterB, PORTB6> B6;
    typedef AvrPin<RegisterB, PORTB7> B7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTC_REGISTER>::address, uint8_t> PortCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINC_REGISTER>::address, uint8_t> PinCInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRC_REGISTER>::address, uint8_t> DdrCInternal;
    typedef AvrIoRegister<PortCInternal, DdrCInternal, PinCInternal> RegisterC;
    typedef AvrPin<RegisterC, PORTC0> C0;
    typedef AvrPin<RegisterC, PORTC1> C1;
    typedef AvrPin<RegisterC, PORTC2> C2;
    typedef AvrPin<RegisterC, PORTC3> C3;
    typedef AvrPin<RegisterC, PORTC4> C4;
    typedef AvrPin<RegisterC, PORTC5> C5;
    typedef AvrPin<RegisterC, PORTC6> C6;
    typedef AvrPin<RegisterC, PORTC7> C7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTD_REGISTER>::address, uint8_t> PortDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PIND_REGISTER>::address, uint8_t> PinDInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRD_REGISTER>::address, uint8_t> DdrDInternal;
    typedef AvrIoRegister<PortDInternal, DdrDInternal, PinDInternal> RegisterD;
    typedef AvrPin<RegisterD, PORTD0> D0;
    typedef AvrPin<RegisterD, PORTD1> D1;
    typedef AvrPin<RegisterD, PORTD2> D2;
    typedef AvrPin<RegisterD, PORTD3> D3;
    typedef AvrPin<RegisterD, PORTD4> D4;
    typedef AvrPin<RegisterD, PORTD5> D5;
    typedef AvrPin<RegisterD, PORTD6> D6;
    typedef AvrPin<RegisterD, PORTD7> D7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTE_REGISTER>::address, uint8_t> PortEInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINE_REGISTER>::address, uint8_t> PinEInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRE_REGISTER>::address, uint8_t> DdrEInternal;
    typedef AvrIoRegister<PortEInternal, DdrEInternal, PinEInternal> RegisterE;
    typedef AvrPin<RegisterE, PORTE0> E0;
    typedef AvrPin<RegisterE, PORTE1> E1;
    typedef AvrPin<RegisterE, PORTE2> E2;
    typedef AvrPin<RegisterE, PORTE3> E3;
    typedef AvrPin<RegisterE, PORTE4> E4;
    typedef AvrPin<RegisterE, PORTE5> E5;
    typedef AvrPin<RegisterE, PORTE6> E6;
    typedef AvrPin<RegisterE, PORTE7> E7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTF_REGISTER>::address, uint8_t> PortFInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINF_REGISTER>::address, uint8_t> PinFInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRF_REGISTER>::address, uint8_t> DdrFInternal;
    typedef AvrIoRegister<PortFInternal, DdrFInternal, PinFInternal> RegisterF;
    typedef AvrPin<RegisterF, PORTF0> F0;
    typedef AvrPin<RegisterF, PORTF1> F1;
    typedef AvrPin<RegisterF, PORTF2> F2;
    typedef AvrPin<RegisterF, PORTF3> F3;
    typedef AvrPin<RegisterF, PORTF4> F4;
    typedef AvrPin<RegisterF, PORTF5> F5;
    typedef AvrPin<RegisterF, PORTF6> F6;
    typedef AvrPin<RegisterF, PORTF7> F7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTG_REGISTER>::address, uint8_t> PortGInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PING_REGISTER>::address, uint8_t> PinGInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRG_REGISTER>::address, uint8_t> DdrGInternal;
    typedef AvrIoRegister<PortGInternal, DdrGInternal, PinGInternal> RegisterG;
    typedef AvrPin<RegisterG, PORTG0> G0;
    typedef AvrPin<RegisterG, PORTG1> G1;
    typedef AvrPin<RegisterG, PORTG2> G2;
    typedef AvrPin<RegisterG, PORTG3> G3;
    typedef AvrPin<RegisterG, PORTG4> G4;
    typedef AvrPin<RegisterG, PORTG5> G5;
    // No access to G6 and G7

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTH_REGISTER>::address, uint8_t> PortHInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINH_REGISTER>::address, uint8_t> PinHInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRH_REGISTER>::address, uint8_t> DdrHInternal;
    typedef AvrIoRegister<PortHInternal, DdrHInternal, PinHInternal> RegisterH;
    typedef AvrPin<RegisterH, PORTH0> H0;
    typedef AvrPin<RegisterH, PORTH1> H1;
    typedef AvrPin<RegisterH, PORTH2> H2;
    typedef AvrPin<RegisterH, PORTH3> H3;
    typedef AvrPin<RegisterH, PORTH4> H4;
    typedef AvrPin<RegisterH, PORTH5> H5;
    typedef AvrPin<RegisterH, PORTH6> H6;
    typedef AvrPin<RegisterH, PORTH7> H7;

    // no I-Register

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTJ_REGISTER>::address, uint8_t> PortJInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINJ_REGISTER>::address, uint8_t> PinJInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRJ_REGISTER>::address, uint8_t> DdrJInternal;
    typedef AvrIoRegister<PortJInternal, DdrJInternal, PinJInternal> RegisterJ;
    typedef AvrPin<RegisterJ, PORTJ0> J0;
    typedef AvrPin<RegisterJ, PORTJ1> J1;
    typedef AvrPin<RegisterJ, PORTJ2> J2;
    typedef AvrPin<RegisterJ, PORTJ3> J3;
    typedef AvrPin<RegisterJ, PORTJ4> J4;
    typedef AvrPin<RegisterJ, PORTJ5> J5;
    typedef AvrPin<RegisterJ, PORTJ6> J6;
    typedef AvrPin<RegisterJ, PORTJ7> J7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTK_REGISTER>::address, uint8_t> PortKInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINK_REGISTER>::address, uint8_t> PinKInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRK_REGISTER>::address, uint8_t> DdrKInternal;
    typedef AvrIoRegister<PortKInternal, DdrKInternal, PinKInternal> RegisterK;
    typedef AvrPin<RegisterK, PORTK0> K0;
    typedef AvrPin<RegisterK, PORTK1> K1;
    typedef AvrPin<RegisterK, PORTK2> K2;
    typedef AvrPin<RegisterK, PORTK3> K3;
    typedef AvrPin<RegisterK, PORTK4> K4;
    typedef AvrPin<RegisterK, PORTK5> K5;
    typedef AvrPin<RegisterK, PORTK6> K6;
    typedef AvrPin<RegisterK, PORTK7> K7;

    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORTL_REGISTER>::address, uint8_t> PortLInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<PINL_REGISTER>::address, uint8_t> PinLInternal;
    typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDRL_REGISTER>::address, uint8_t> DdrLInternal;
    typedef AvrIoRegister<PortLInternal, DdrLInternal, PinLInternal> RegisterL;
    typedef AvrPin<RegisterL, PORTL0> L0;
    typedef AvrPin<RegisterL, PORTL1> L1;
    typedef AvrPin<RegisterL, PORTL2> L2;
    typedef AvrPin<RegisterL, PORTL3> L3;
    typedef AvrPin<RegisterL, PORTL4> L4;
    typedef AvrPin<RegisterL, PORTL5> L5;
    typedef AvrPin<RegisterL, PORTL6> L6;
    typedef AvrPin<RegisterL, PORTL7> L7;
};

#endif // ATMEGA328P_HPP
