#ifndef TMP_AVRPIN_HPP
#define TMP_AVRPIN_HPP

#include "avrinputoutput.hpp"

// Struct for handling a single pin in a register conveniently.
template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPin
{
    typedef AvrIoRegister Register;
    enum { pinNumber = pinNumber_,
           bitMask = _BV(pinNumber) };

    static void setType(AvrInputOutput::PinType const pinType)
    {
        AvrIoRegister::setType(pinType, bitMask);
    }

    // ----------------------------------------------------------------------------------------------------

    static void togglePort()
    {
        AvrIoRegister::togglePort(bitMask);
    }

    static void setPort()
    {
        AvrIoRegister::setPort(bitMask);
    }

    static void clearPort()
    {
        AvrIoRegister::clearPort(bitMask);
    }

    static typename AvrInputOutput::PinState readPort()
    {
        return checkPinState_(AvrIoRegister::readPort());
    }

    // ----------------------------------------------------------------------------------------------------

    static void togglePin()
    {
        AvrIoRegister::togglePin(bitMask);
    }

    static void setPin()
    {
        AvrIoRegister::setPin(bitMask);
    }

    static void clearPin()
    {
        AvrIoRegister::clearPin(bitMask);
    }

    static typename AvrInputOutput::PinState readPin()
    {
        return checkPinState_(AvrIoRegister::readPin());
    }

    // ----------------------------------------------------------------------------------------------------

    static void toggleDdr()
    {
        AvrIoRegister::toggleDdr(bitMask);
    }

    static void setDdr()
    {
        AvrIoRegister::setDdr(bitMask);
    }

    static void clearDdr()
    {
        AvrIoRegister::clearDdr(bitMask);
    }

    static typename AvrInputOutput::PinState readDdr()
    {
        return checkPinState_(AvrIoRegister::readDdr());
    }

    // ----------------------------------------------------------------------------------------------------

protected:
    // this checks, whether the pin is set in the registerValue or not -
    // if it is, this method returns HIGH, otherwise LOW.
    static typename AvrInputOutput::PinState checkPinState_(typename AvrIoRegister::RegisterType const registerValue)
    {
        return ((registerValue & bitMask) != 0) ? AvrInputOutput::High : AvrInputOutput::Low;
    }
};

#endif // TMP_AVRPIN_HPP
