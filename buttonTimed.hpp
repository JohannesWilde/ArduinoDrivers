#ifndef TMP_BUTTON_DURATION_HPP
#define TMP_BUTTON_DURATION_HPP

// ----------------------------------------------------------------------------------------------------

#include "button.hpp"

// ----------------------------------------------------------------------------------------------------

namespace ButtonTimedProperties
{

typedef uint8_t Duration_t; // in number of update() calls [must be unsigned, see update()]

enum ButtonStateDuration
{
    TooShort,
    Short,
    Long
};

} // namespace ButtonTimedProperties

// ----------------------------------------------------------------------------------------------------

template <typename AvrPin_,
          AvrInputOutput::PinState PinDownState_,
          bool PullupEnabled_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
class ButtonTimed : public Button<AvrPin_, PinDownState_, PullupEnabled_>
{
public:
    static ButtonTimedProperties::Duration_t  constexpr DurationShort = DurationShort_;
    static ButtonTimedProperties::Duration_t  constexpr DurationLong = DurationLong_;

    static void initialize()
    {
        Button<AvrPin_, PinDownState_, PullupEnabled_>::initialize();
        currentDuration_ = 0;
        previousDuration_ = 0;
    }

    static void update()
    {
        Button<AvrPin_, PinDownState_, PullupEnabled_>::update();

        if (Button<AvrPin_, PinDownState_, PullupEnabled_>::getCurrentState_() !=
                Button<AvrPin_, PinDownState_, PullupEnabled_>::getPreviousState_())
        {
            previousDuration_ = currentDuration_;
            currentDuration_ = 0;
        }
        else
        {
            // only increase up to max of Duration_t, do not overflow!
            if (currentDuration_ < static_cast<ButtonTimedProperties::Duration_t>(-1))
            {
                ++currentDuration_;
            }
        }
    }

    static ButtonTimedProperties::ButtonStateDuration currentState()
    {
        return durationToState(currentDuration_);
    }

    static ButtonTimedProperties::ButtonStateDuration previousState()
    {
        return durationToState(previousDuration_);
    }

    // convenience access methods

    static bool isDownShort()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::isDown() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == currentState()));
    }

    static bool isDownLong()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::isDown() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == currentState()));
    }

    static bool isUpShort()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::isUp() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == currentState()));
    }

    static bool isUpLong()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::isUp() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == currentState()));
    }

    static bool pressedAfterShort()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::pressed() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == previousState()));
    }

    static bool pressedAfterLong()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::pressed() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == previousState()));
    }

    static bool releasedAfterShort()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::released() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == previousState()));
    }

    static bool releasedAfterLong()
    {
        return (Button<AvrPin_, PinDownState_, PullupEnabled_>::released() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == previousState()));
    }

protected:
    static ButtonTimedProperties::Duration_t getCurrentDuration_()
    {
        return currentDuration_;
    }

    static ButtonTimedProperties::Duration_t getPreviousDuration_()
    {
        return previousDuration_;
    }


private:
    static ButtonTimedProperties::Duration_t currentDuration_;
    static ButtonTimedProperties::Duration_t previousDuration_;

    static ButtonTimedProperties::ButtonStateDuration durationToState(ButtonTimedProperties::Duration_t const & duration)
    {
        ButtonTimedProperties::ButtonStateDuration state = ButtonTimedProperties::ButtonStateDuration::TooShort;
        if (duration >= DurationLong_)
        {
            state = ButtonTimedProperties::ButtonStateDuration::Long;
        }
        else if (duration >= DurationShort_)
        {
            state = ButtonTimedProperties::ButtonStateDuration::Short;
        }
        return state;
    }
};

// ----------------------------------------------------------------------------------------------------

template <typename AvrPin_,
          AvrInputOutput::PinState PinDownState_,
          bool PullupEnabled_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
ButtonTimedProperties::Duration_t ButtonTimed<AvrPin_, PinDownState_, PullupEnabled_, DurationShort_, DurationLong_>::currentDuration_;

template <typename AvrPin_,
          AvrInputOutput::PinState PinDownState_,
          bool PullupEnabled_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
ButtonTimedProperties::Duration_t ButtonTimed<AvrPin_, PinDownState_, PullupEnabled_, DurationShort_, DurationLong_>::previousDuration_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_DURATION_HPP
