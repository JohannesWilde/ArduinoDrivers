// ATMEL ATMEGA328p

#ifndef ARDUINO_MEGA_HPP
#define ARDUINO_MEGA_HPP

#ifndef __AVR_ATmega2560__
#warning "An Arduino Mega typically has an Atmega328p - currently something else is #defined."
#endif

#include "atmega2560.hpp"

struct ArduinoMega : Atmega2560
{
public:
    // The individual Arduino Mega Pins.
    // mapping from https://www.arduino.cc/en/Hacking/PinMapping2560
    typedef typename Atmega2560::A0 D22;
    typedef typename Atmega2560::A1 D23;
    typedef typename Atmega2560::A2 D24;
    typedef typename Atmega2560::A3 D25;
    typedef typename Atmega2560::A4 D26;
    typedef typename Atmega2560::A5 D27;
    typedef typename Atmega2560::A6 D28;
    typedef typename Atmega2560::A7 D29;

    typedef typename Atmega2560::B0 D53;
    typedef typename Atmega2560::B1 D52;
    typedef typename Atmega2560::B2 D51;
    typedef typename Atmega2560::B3 D50;
    typedef typename Atmega2560::B4 D10;
    typedef typename Atmega2560::B5 D11;
    typedef typename Atmega2560::B6 D12;
    typedef typename Atmega2560::B7 D13;

    typedef typename Atmega2560::C0 D37;
    typedef typename Atmega2560::C1 D36;
    typedef typename Atmega2560::C2 D35;
    typedef typename Atmega2560::C3 D34;
    typedef typename Atmega2560::C4 D33;
    typedef typename Atmega2560::C5 D32;
    typedef typename Atmega2560::C6 D31;
    typedef typename Atmega2560::C7 D30;

    typedef typename Atmega2560::D0 D21;
    typedef typename Atmega2560::D1 D20;
    typedef typename Atmega2560::D2 D19;
    typedef typename Atmega2560::D3 D18;
//    typedef typename Atmega2560::D4 ; // ICP1
//    typedef typename Atmega2560::D5 ; // XCK1
//    typedef typename Atmega2560::D6 ; // T1
    typedef typename Atmega2560::D7 D38;

    typedef typename Atmega2560::E0 D0;
    typedef typename Atmega2560::E1 D1;
//    typedef typename Atmega2560::E2 ; // XCK0
    typedef typename Atmega2560::E3 D5;
    typedef typename Atmega2560::E4 D2;
    typedef typename Atmega2560::E5 D3;
//    typedef typename Atmega2560::E6 ; // T3
//    typedef typename Atmega2560::E7 ; // CLK0

    typedef typename Atmega2560::F0 A0;
    typedef typename Atmega2560::F1 A1;
    typedef typename Atmega2560::F2 A2;
    typedef typename Atmega2560::F3 A3;
    typedef typename Atmega2560::F4 A4;
    typedef typename Atmega2560::F5 A5;
    typedef typename Atmega2560::F6 A6;
    typedef typename Atmega2560::F7 A7;

    typedef typename Atmega2560::G0 D41;
    typedef typename Atmega2560::G1 D40;
    typedef typename Atmega2560::G2 D39;
//    typedef typename Atmega2560::G3 ; // TOSC2
//    typedef typename Atmega2560::G4 ; // TOSC1
    typedef typename Atmega2560::G5 D4;

    typedef typename Atmega2560::H0 D17;
    typedef typename Atmega2560::H1 D16;
//    typedef typename Atmega2560::H2 ; // XCK2
    typedef typename Atmega2560::H3 D6;
    typedef typename Atmega2560::H4 D7;
    typedef typename Atmega2560::H5 D8;
    typedef typename Atmega2560::H6 D9;
//    typedef typename Atmega2560::H7 ; // T4

    typedef typename Atmega2560::J0 D15;
    typedef typename Atmega2560::J1 D14;
//    typedef typename Atmega2560::J2 ; // SCK3
//    typedef typename Atmega2560::J3 ; // PCINT12
//    typedef typename Atmega2560::J4 ; // PCINT13
//    typedef typename Atmega2560::J5 ; // PCINT14
//    typedef typename Atmega2560::J6 ; // PCINT15
//    typedef typename Atmega2560::J7 ;

    typedef typename Atmega2560::K0 A8;
    typedef typename Atmega2560::K1 A9;
    typedef typename Atmega2560::K2 A10;
    typedef typename Atmega2560::K3 A11;
    typedef typename Atmega2560::K4 A12;
    typedef typename Atmega2560::K5 A13;
    typedef typename Atmega2560::K6 A14;
    typedef typename Atmega2560::K7 A15;

    typedef typename Atmega2560::L0 D49;
    typedef typename Atmega2560::L1 D48;
    typedef typename Atmega2560::L2 D47;
    typedef typename Atmega2560::L3 D46;
    typedef typename Atmega2560::L4 D45;
    typedef typename Atmega2560::L5 D44;
    typedef typename Atmega2560::L6 D43;
    typedef typename Atmega2560::L7 D42;

    // convenience names
    typedef D13 LED_BUILTIN;
};

#endif // ARDUINO_MEGA_HPP
