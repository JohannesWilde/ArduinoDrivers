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
        switch (OnOff::get())
        {
        case SimpleOnOffProperties::State::On: return State::Down;
        case SimpleOnOffProperties::State::Off: return State::Up;
        }

        // Appease the compiler even though I don't see how above switch-case could not cover every possibility.
        return State::Up;
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
