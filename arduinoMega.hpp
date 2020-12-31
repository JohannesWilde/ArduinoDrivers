// ATMEL ATMEGA328p

#ifndef TMP_ARDUINO_MEGA_HPP
#define TMP_ARDUINO_MEGA_HPP

#ifndef __AVR_ATmega2560__
#warning "An Arduino Mega typically has an Atmega328p - currently something else is #defined."
#endif

#include "atmega2560.hpp"

struct ArduinoMega : Atmega2560
{
public:
    // The individual Arduino Mega Pins.
    // mapping from https://www.arduino.cc/en/Hacking/PinMapping2560
    typedef typename Atmega2560::pinA0 D22;
    typedef typename Atmega2560::pinA1 D23;
    typedef typename Atmega2560::pinA2 D24;
    typedef typename Atmega2560::pinA3 D25;
    typedef typename Atmega2560::pinA4 D26;
    typedef typename Atmega2560::pinA5 D27;
    typedef typename Atmega2560::pinA6 D28;
    typedef typename Atmega2560::pinA7 D29;

    typedef typename Atmega2560::pinB0 D53;
    typedef typename Atmega2560::pinB1 D52;
    typedef typename Atmega2560::pinB2 D51;
    typedef typename Atmega2560::pinB3 D50;
    typedef typename Atmega2560::pinB4 D10;
    typedef typename Atmega2560::pinB5 D11;
    typedef typename Atmega2560::pinB6 D12;
    typedef typename Atmega2560::pinB7 D13;

    typedef typename Atmega2560::pinC0 D37;
    typedef typename Atmega2560::pinC1 D36;
    typedef typename Atmega2560::pinC2 D35;
    typedef typename Atmega2560::pinC3 D34;
    typedef typename Atmega2560::pinC4 D33;
    typedef typename Atmega2560::pinC5 D32;
    typedef typename Atmega2560::pinC6 D31;
    typedef typename Atmega2560::pinC7 D30;

    typedef typename Atmega2560::pinD0 D21;
    typedef typename Atmega2560::pinD1 D20;
    typedef typename Atmega2560::pinD2 D19;
    typedef typename Atmega2560::pinD3 D18;
//    typedef typename Atmega2560::pinD4 ; // ICP1
//    typedef typename Atmega2560::pinD5 ; // XCK1
//    typedef typename Atmega2560::pinD6 ; // T1
    typedef typename Atmega2560::pinD7 D38;

    typedef typename Atmega2560::pinE0 D0;
    typedef typename Atmega2560::pinE1 D1;
//    typedef typename Atmega2560::pinE2 ; // XCK0
    typedef typename Atmega2560::pinE3 D5;
    typedef typename Atmega2560::pinE4 D2;
    typedef typename Atmega2560::pinE5 D3;
//    typedef typename Atmega2560::pinE6 ; // T3
//    typedef typename Atmega2560::pinE7 ; // CLK0

    typedef typename Atmega2560::pinF0 A0;
    typedef typename Atmega2560::pinF1 A1;
    typedef typename Atmega2560::pinF2 A2;
    typedef typename Atmega2560::pinF3 A3;
    typedef typename Atmega2560::pinF4 A4;
    typedef typename Atmega2560::pinF5 A5;
    typedef typename Atmega2560::pinF6 A6;
    typedef typename Atmega2560::pinF7 A7;

    typedef typename Atmega2560::pinG0 D41;
    typedef typename Atmega2560::pinG1 D40;
    typedef typename Atmega2560::pinG2 D39;
//    typedef typename Atmega2560::pinG3 ; // TOSC2
//    typedef typename Atmega2560::pinG4 ; // TOSC1
    typedef typename Atmega2560::pinG5 D4;

    typedef typename Atmega2560::pinH0 D17;
    typedef typename Atmega2560::pinH1 D16;
//    typedef typename Atmega2560::pinH2 ; // XCK2
    typedef typename Atmega2560::pinH3 D6;
    typedef typename Atmega2560::pinH4 D7;
    typedef typename Atmega2560::pinH5 D8;
    typedef typename Atmega2560::pinH6 D9;
//    typedef typename Atmega2560::pinH7 ; // T4

    typedef typename Atmega2560::pinJ0 D15;
    typedef typename Atmega2560::pinJ1 D14;
//    typedef typename Atmega2560::pinJ2 ; // SCK3
//    typedef typename Atmega2560::pinJ3 ; // PCINT12
//    typedef typename Atmega2560::pinJ4 ; // PCINT13
//    typedef typename Atmega2560::pinJ5 ; // PCINT14
//    typedef typename Atmega2560::pinJ6 ; // PCINT15
//    typedef typename Atmega2560::pinJ7 ;

    typedef typename Atmega2560::pinK0 A8;
    typedef typename Atmega2560::pinK1 A9;
    typedef typename Atmega2560::pinK2 A10;
    typedef typename Atmega2560::pinK3 A11;
    typedef typename Atmega2560::pinK4 A12;
    typedef typename Atmega2560::pinK5 A13;
    typedef typename Atmega2560::pinK6 A14;
    typedef typename Atmega2560::pinK7 A15;

    typedef typename Atmega2560::pinL0 D49;
    typedef typename Atmega2560::pinL1 D48;
    typedef typename Atmega2560::pinL2 D47;
    typedef typename Atmega2560::pinL3 D46;
    typedef typename Atmega2560::pinL4 D45;
    typedef typename Atmega2560::pinL5 D44;
    typedef typename Atmega2560::pinL6 D43;
    typedef typename Atmega2560::pinL7 D42;

    // convenience names
    typedef D13 BUILTIN_LED;
};

#endif // TMP_ARDUINO_MEGA_HPP
