#ifndef TMP_SIMPLE_PIN_AVR_HPP
#define TMP_SIMPLE_PIN_AVR_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"
#include "avrpin.hpp"

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

namespace Internal
{

/**
 * @brief The SimplePinAvrRead_ class provides the base functionality.
 * I only introduced it to be able to assert the PinType_ in the actual SimplePinAvrRead
 * class and still be able to use this as a base class for SimplePinAvr.
 */
template <typename AvrPin_,
         AvrInputOutput::PinType PinType_>
class SimplePinAvrRead_ : public SimplePin
{
public:
    typedef AvrPin_ Pin;
    //    static AvrInputOutput::PinType constexpr PinType = PinType_;

    static void initialize()
    {
        AvrPin_::setType(PinType_);
    }

    static void deinitialize()
    {
        // intentionally empty
        AvrPin_::setType(AvrInputOutput::PinType::Input);
    }

    static State get()
    {
        return convert_(AvrPin_::readPin());
    }

protected:

    static constexpr State convert_(AvrInputOutput::PinState const pinState)
    {
        switch (pinState)
        {
        case AvrInputOutput::PinState::Low: return State::Zero;
        case AvrInputOutput::PinState::High: return State::One;
        }

        // Appease the compiler even though I don't see how above switch-case could not cover every possibility.
        return State::One;
    }

private:

    SimplePinAvrRead_() = delete;

};

} // namespace Internal

// ----------------------------------------------------------------------------------------------------

template <typename AvrPin_,
          AvrInputOutput::PinType PinType_>
class SimplePinAvrRead : public Internal::SimplePinAvrRead_<AvrPin_, PinType_>
{
public:
    typedef AvrPin_ Pin;
//    static AvrInputOutput::PinType constexpr PinType = PinType_;
    static_assert((AvrInputOutput::PinType::Input == PinType_) ||
                  (AvrInputOutput::PinType::InputPullup == PinType_));

private:

    SimplePinAvrRead() = delete;

};

// ----------------------------------------------------------------------------------------------------


template <typename AvrPin_,
         AvrInputOutput::PinType PinType_>
class SimplePinAvr : public Internal::SimplePinAvrRead_<AvrPin_, PinType_>
{
public:
    typedef Internal::SimplePinAvrRead_<AvrPin_, PinType_> Base;

    static void set(SimplePin::State const state)
    {
        AvrPin_::setPin(convert_(state));
    }

    static void toggle()
    {
        AvrPin_::togglePin();
    }

protected:

    static constexpr AvrInputOutput::PinState convert_(SimplePin::State const pinState)
    {
        switch (pinState)
        {
        case SimplePin::State::Zero: return AvrInputOutput::PinState::Low;
        case SimplePin::State::One: return AvrInputOutput::PinState::High;
        }

        // Appease the compiler even though I don't see how above switch-case could not cover every possibility.
        return AvrInputOutput::PinState::High;
    }

private:

    SimplePinAvr() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_PIN_AVR_HPP
