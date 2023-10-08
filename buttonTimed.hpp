#ifndef TMP_BUTTON_TIMED_HPP
#define TMP_BUTTON_TIMED_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonChanged.hpp"

#include <limits.h>
#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

namespace ButtonTimedProperties
{

typedef uint8_t Duration_t; // in number of update() calls [must be unsigned, see update()]

enum class Duration
{
    TooShort,
    Short,
    Long
};

} // namespace ButtonTimedProperties

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
class ButtonTimed : public ButtonChanged<Button_>
{
    typedef ButtonChanged<Button_> BaseButton;

public:
//    static ButtonTimedProperties::Duration_t  constexpr DurationShort = DurationShort_;
//    static ButtonTimedProperties::Duration_t  constexpr DurationLong = DurationLong_;

    static_assert(0 < DurationShort_);
    static_assert(DurationShort_ < DurationLong_);

    static void initialize()
    {
        BaseButton::initialize();
        currentDuration_ = 0;
        previousDuration_ = 0;
    }

    static void update()
    {
        BaseButton::update();

        if (BaseButton::toggled())
        {
            previousDuration_ = currentDuration_;
            currentDuration_ = 1;
        }
        else
        {
            // Only increase up to max of Duration_t - do not overflow!
            static_assert(UCHAR_MAX == static_cast<ButtonTimedProperties::Duration_t>(-1));
            if (currentDuration_ < UCHAR_MAX)
            {
                ++currentDuration_;
            }
        }
    }

    static ButtonTimedProperties::Duration currentState()
    {
        return durationToState(currentDuration_);
    }

    static ButtonTimedProperties::Duration previousState()
    {
        return durationToState(previousDuration_);
    }

    // convenience access methods

    static bool isDownShort()
    {
        return (BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Short == currentState()));
    }

    static bool isDownLong()
    {
        return (BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Long == currentState()));
    }

    static bool isUpShort()
    {
        return (BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Short == currentState()));
    }

    static bool isUpLong()
    {
        return (BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Long == currentState()));
    }

    static bool pressedAfterShort()
    {
        return (BaseButton::pressed() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    static bool pressedAfterLong()
    {
        return (BaseButton::pressed() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    static bool releasedAfterShort()
    {
        return (BaseButton::released() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    static bool releasedAfterLong()
    {
        return (BaseButton::released() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    static bool wasDownShort()
    {
        return (!BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    static bool wasDownLong()
    {
        return (!BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    static bool wasUpShort()
    {
        return (!BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    static bool wasUpLong()
    {
        return (!BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

//protected:
//    static ButtonTimedProperties::Duration_t getCurrentDuration_()
//    {
//        return currentDuration_;
//    }

//    static ButtonTimedProperties::Duration_t getPreviousDuration_()
//    {
//        return previousDuration_;
//    }


private:
    static ButtonTimedProperties::Duration_t currentDuration_;
    static ButtonTimedProperties::Duration_t previousDuration_;

    static ButtonTimedProperties::Duration durationToState(ButtonTimedProperties::Duration_t const & duration)
    {
        ButtonTimedProperties::Duration state = ButtonTimedProperties::Duration::TooShort;
        if (duration >= DurationLong_)
        {
            state = ButtonTimedProperties::Duration::Long;
        }
        else if (duration >= DurationShort_)
        {
            state = ButtonTimedProperties::Duration::Short;
        }
        return state;
    }

    ButtonTimed() = delete;

};

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
ButtonTimedProperties::Duration_t ButtonTimed<Button_, DurationShort_, DurationLong_>::currentDuration_;

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_>
ButtonTimedProperties::Duration_t ButtonTimed<Button_, DurationShort_, DurationLong_>::previousDuration_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_TIMED_HPP
