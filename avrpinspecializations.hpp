#ifndef AVR_PIN_SPECIALIZATIONS_HPP
#define AVR_PIN_SPECIALIZATIONS_HPP

#include "avrinputoutput.hpp"
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

namespace // anonymous
{

template<class AvrPin, AvrInputOutput::PinState pinState>
struct AvrPinOutputHelper
{
    static void initialize();
    static void write();
};

template<class AvrPin>
struct AvrPinOutputHelper<AvrPin, AvrInputOutput::PinState::High>
{
    static void initialize()
    {
        AvrPin::setType(AvrInputOutput::OutputHigh);
    }
    static void write()
    {
        AvrPin::setPort();
    }
};

template<class AvrPin>
struct AvrPinOutputHelper<AvrPin, AvrInputOutput::PinState::Low>
{
    static void initialize()
    {
        AvrPin::setType(AvrInputOutput::OutputLow);
    }
    static void write()
    {
        AvrPin::clearPort();
    }
};

} // namespace anonymous



template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInput : protected AvrPin<AvrIoRegister, pinNumber_>
{
    // static void initialize() = 0;

    static AvrInputOutput::PinState read()
    {
        return avrPin_::readPin();
    }

protected:
    typedef AvrPin<AvrIoRegister, pinNumber_> avrPin_;
};


template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInputFloating : private AvrPinInput<AvrIoRegister, pinNumber_>
{
    static void initialize()
    {
        avrPin_::setType(AvrInputOutput::Input);
    }

private:
    typedef typename AvrPinInput<AvrIoRegister, pinNumber_>::avrPin_ avrPin_;
};


template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinInputPullup : private AvrPin<AvrIoRegister, pinNumber_>
{
    static void initialize()
    {
        avrPin_::setType(AvrInputOutput::InputPullup);
    }

private:
    typedef typename AvrPinInput<AvrIoRegister, pinNumber_>::avrPin_ avrPin_;
};


template<typename AvrIoRegister, unsigned pinNumber_>
struct AvrPinOutput : private AvrPin<AvrIoRegister, pinNumber_>
{
    template<AvrInputOutput::PinState pinState>
    static void initialize()
    {
        AvrPinOutputHelper<avrPin_, pinState>::initialize();
    }

    template<AvrInputOutput::PinState pinState>
    static void write()
    {
        AvrPinOutputHelper<avrPin_, pinState>::write();
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
