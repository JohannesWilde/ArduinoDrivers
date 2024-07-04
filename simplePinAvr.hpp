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
        State state = State::One;

        switch (pinState)
        {
        case AvrInputOutput::PinState::Low:
        {
            state = State::Zero;
            break;
        }
        case AvrInputOutput::PinState::High:
        {
            state = State::One;
            break;
        }
        }

        return state;
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
        AvrInputOutput::PinState pinStateConverted = AvrInputOutput::PinState::High;

        switch (pinState)
        {
        case SimplePin::State::Zero:
        {
            pinStateConverted = AvrInputOutput::PinState::Low;
            break;
        }
        case SimplePin::State::One:
        {
            pinStateConverted = AvrInputOutput::PinState::High;
            break;
        }
        }

        return pinStateConverted;
    }

private:

    SimplePinAvr() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_PIN_AVR_HPP
