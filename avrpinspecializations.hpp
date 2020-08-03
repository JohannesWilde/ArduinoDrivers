#ifndef AVR_PIN_SPECIALIZATIONS_HPP
#define AVR_PIN_SPECIALIZATIONS_HPP

#include "avrpin.hpp"

template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInput : private AvrPin<AvrIoRegister, pinNumber_>
{
    AvrPinInput()
    {
        avrPin_::setType(AvrInputOutput::Input);
    }

    AvrInputOutput::PinState read()
    {
        return avrPin_::readPin();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInputPullup : private AvrPin<AvrIoRegister, pinNumber_>
{
    AvrPinInputPullup()
    {
        avrPin_::setType(AvrInputOutput::InputPullup);
    }

    AvrInputOutput::PinState read()
    {
        return avrPin_::readPin();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinOutput : private AvrPin<AvrIoRegister, pinNumber_>
{
    AvrPinOutput(AvrInputOutput::PinState const pinState)
    {
        AvrInputOutput::PinType const initialState = (AvrInputOutput::High == pinState) ? AvrInputOutput::OutputHigh : AvrInputOutput::OutputLow;
        AvrPin<AvrIoRegister, pinNumber_>::setType(initialState);
    }

    template<AvrInputOutput::PinState pinState>
    void write();

    template<>
    void write<AvrInputOutput::High>()
    {
        avrPin_::setPort();
    }

    template<>
    void write<AvrInputOutput::Low>()
    {
        avrPin_::clearPort();
    }

    void toggle()
    {
        avrPin_::togglePort();
    }

//    AvrInputOutput::PinState readPin()
//    {
//        return avrPin_::readPin();
//    }

    AvrInputOutput::PinState read()
    {
        return avrPin_::readPort();
    }

private:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};

#endif // AVR_PIN_SPECIALIZATIONS_HPP
