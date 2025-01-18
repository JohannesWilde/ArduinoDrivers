#ifndef TMP_BUTTON_HPP
#define TMP_BUTTON_HPP

// ----------------------------------------------------------------------------------------------------

#include "simpleOnOff.hpp"
#include "simplePin.hpp"

// ----------------------------------------------------------------------------------------------------

enum class ButtonState
{
    Up,
    Down
};

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

    using OnOff::initialize;
    using OnOff::deinitialize;

    static ButtonState get()
    {
        ButtonState state = ButtonState::Up;

        switch (OnOff::get())
        {
        case SimpleOnOffProperties::State::On:
        {
            state = ButtonState::Down;
            break;
        }
        case SimpleOnOffProperties::State::Off:
        {
            state = ButtonState::Up;
            break;
        }
        }

        return state;
    }

    static bool isDown()
    {
        return (ButtonState::Down == get());
    }

    static bool isUp()
    {
        return (ButtonState::Up == get());
    }

private:

    Button() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_HPP
