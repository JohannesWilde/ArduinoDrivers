#ifndef AVR_PIN_SPECIALIZATIONS_HPP
#define AVR_PIN_SPECIALIZATIONS_HPP

#include "avrpin.hpp"

/** AvrPinSpecializations - Classes abstracting the internal interface for
 * using Avr pins.
 * These classes are stripped to their bare minimum and support only the
 * necessary functionality for the respective type.
 * Please note that it is currently not supported to change the type of
 * the pin during execution.
 *
 * As however all of these are template classes, one could create typedefs
 * of different types [e.g. AvrPinInput and AvrPinOutput] for the same pin
 * and re-"initialize()" those anywhere in the program - please note however
 * that you as the user are responsible for having these classes correctly
 * initialized before using any of their member functions.
 */


template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInput : private AvrPin<AvrIoRegister, pinNumber_>
{
    static void initialize()
    {
        avrPin_::setType(AvrInputOutput::Input);
    }

    static AvrInputOutput::PinState read()
    {
        return avrPin_::readPin();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInputPullup : private AvrPin<AvrIoRegister, pinNumber_>
{
    static void initialize()
    {
        avrPin_::setType(AvrInputOutput::InputPullup);
    }

    static AvrInputOutput::PinState read()
    {
        return avrPin_::readPin();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinOutput : private AvrPin<AvrIoRegister, pinNumber_>
{
    template<AvrInputOutput::PinState pinState>
    static void initialize();

    template<>
    static void initialize<AvrInputOutput::High>()
    {
        avrPin_::setType(AvrInputOutput::OutputHigh);
    }

    template<>
    static void initialize<AvrInputOutput::Low>()
    {
        avrPin_::setType(AvrInputOutput::OutputLow);
    }


    template<AvrInputOutput::PinState pinState>
    static void write();

    template<>
    static void write<AvrInputOutput::High>()
    {
        avrPin_::setPort();
    }

    template<>
    static void write<AvrInputOutput::Low>()
    {
        avrPin_::clearPort();
    }


    static void toggle()
    {
        avrPin_::togglePort();
    }

//    static AvrInputOutput::PinState read()
//    {
//        return avrPin_::readPin();
//    }

    static AvrInputOutput::PinState read()
    {
        return avrPin_::readPort();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

#endif // AVR_PIN_SPECIALIZATIONS_HPP
