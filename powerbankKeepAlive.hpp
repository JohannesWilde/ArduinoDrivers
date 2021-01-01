#ifndef POWERBANK_KEEP_ALIVE_HPP
#define POWERBANK_KEEP_ALIVE_HPP

#include <stdint.h>
#include "avrpin.hpp"

namespace PowerbankKeepAliveProperties
{

typedef uint8_t Duration_t; // in number of update() calls

enum State
{
    Active = AvrInputOutput::PinState::High,
    Inactive = AvrInputOutput::PinState::Low
};

} // namespace PowerbankKeepAliveProperties

/**
 * PowerbankKeepAlive instance which simulates pressing the Powerbank button periodically.
 * For me this is currently required, because my Arduino uses less current
 * than the powerbank needs to output at least before turning off
 * automatically. Continuously or long-pressing the powerbank power-button
 * does not work, a periodic short press however does.
 * Please note that for this to work the update() method will have to be
 * called periodically. Most optimally during an interrupt.
 * Please also note that the Time_t is in number of calls to the update()
 * method [and not milliseconds or something similar].
 * Further note that the AvrPin is assumed to be configured by this class
 * alone - in case anyone else reconfigures it, this class won't work as
 * intended.
 */
template<typename AvrPin_,
         PowerbankKeepAliveProperties::Duration_t DurationActive_,
         PowerbankKeepAliveProperties::Duration_t DurationInactive_>
class PowerbankKeepAlive
{
    static_assert (DurationActive_ > 0, "PowerbankKeepAlive::DurationActive_ must be greater than 0.");
    static_assert (DurationInactive_ > 0, "PowerbankKeepAlive::DurationInactive_ must be greater than 0.");

public:
    typedef AvrPin_ Pin;
    static PowerbankKeepAliveProperties::Duration_t constexpr DurationActive = DurationActive_;
    static PowerbankKeepAliveProperties::Duration_t constexpr DurationInactive = DurationInactive_;

    static void initialize(PowerbankKeepAliveProperties::State const beginState = PowerbankKeepAliveProperties::State::Inactive)
    {
        AvrPin_::clearPort(); // PORTxn = 0 => output low or input without pull-up
        updateTimesSinceLastToggle_ = 0;
        setState_(beginState);
    }

    static void deinitialize()
    {
        setState_(PowerbankKeepAliveProperties::State::Inactive);
    }

    static bool isActive()
    {
        AvrInputOutput::PinState const currentState = AvrPin_::readDdr();
        return (AvrInputOutput::PinState::High == currentState);
    }

    // This relies on DurationAcitve_ and DurationInactive_ being greater than 0
    // [everything else would make no sense anyway].
    static void update()
    {
        ++updateTimesSinceLastToggle_;

        AvrInputOutput::PinState const currentState = AvrPin_::readDdr();
        switch (currentState)
        {
        case PowerbankKeepAliveProperties::State::Active:
        {
            if (DurationActive_ == updateTimesSinceLastToggle_)
            {
                setState_(PowerbankKeepAliveProperties::State::Inactive);
                updateTimesSinceLastToggle_ = 0;
            }
            break;
        }
        case PowerbankKeepAliveProperties::State::Inactive:
        {
            if (DurationInactive_ == updateTimesSinceLastToggle_)
            {
                setState_(PowerbankKeepAliveProperties::State::Active);
                updateTimesSinceLastToggle_ = 0;
            }
            break;
        }
        }
    }

private:
    static PowerbankKeepAliveProperties::Duration_t updateTimesSinceLastToggle_;

    static void setState_(PowerbankKeepAliveProperties::State const state)
    {
        switch (state)
        {
        case PowerbankKeepAliveProperties::State::Active:
        {
            AvrPin_::setDdr();
            break;
        }
        case PowerbankKeepAliveProperties::State::Inactive:
        {
            AvrPin_::clearDdr();
            break;
        }
        }
    }

};


template<typename AvrPin_,
         PowerbankKeepAliveProperties::Duration_t DurationActive_,
         PowerbankKeepAliveProperties::Duration_t DurationInactive_>
PowerbankKeepAliveProperties::Duration_t PowerbankKeepAlive<AvrPin_, DurationActive_, DurationInactive_>::updateTimesSinceLastToggle_;

#endif // POWERBANK_KEEP_ALIVE_HPP
