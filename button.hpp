#ifndef TMP_BUTTON_HPP
#define TMP_BUTTON_HPP

// ----------------------------------------------------------------------------------------------------

#include "simpleOnOff.hpp"
#include "simplePin.hpp"

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

/**
 * @brief Button interpretes simplePin values for button behaviour.
 */
template <typename SimplePinRead_,
         SimplePin::State DownState_>
class Button : private SimpleOnOff<SimplePinRead_, DownState_>
{
public:
    typedef SimplePinRead_ Pin;
//    static Pin::State constexpr DownState = DownState;
    typedef SimpleOnOff<SimplePinRead_, DownState_> OnOff;

    enum class State
    {
        Up,
        Down
    };

    using OnOff::initialize;
    using OnOff::deinitialize;

    static State get()
    {
        State state = State::Up;

        switch (OnOff::get())
        {
        case SimpleOnOffProperties::State::On:
        {
            state = State::Down;
            break;
        }
        case SimpleOnOffProperties::State::Off:
        {
            state = State::Up;
            break;
        }
        }

        return state;
    }

    static bool isDown()
    {
        return (State::Down == get());
    }

    static bool isUp()
    {
        return (State::Up == get());
    }

private:

    Button() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_HPP
