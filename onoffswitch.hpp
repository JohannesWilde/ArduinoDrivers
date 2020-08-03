#ifndef ON_OFF_SWITCH_HPP
#define ON_OFF_SWITCH_HPP

#include "avrpinspecializations.hpp"

namespace AvrDriver
{

enum SwitchState
{
    On,
    Off
};

template<typename AvrPinInput_, AvrInputOutput::PinState onState>
struct OnOffSwitch
{
    static void initialize()
    {
        avrPinInput::initialize();
    }

    static SwitchState read()
    {
        return (avrPinInput::read() == onState) ? SwitchState::On : SwitchState::Off;
    }

private:
    typedef AvrPinInput_ avrPinInput;
};

} // AvrDriver

#endif // ON_OFF_SWITCH_HPP
