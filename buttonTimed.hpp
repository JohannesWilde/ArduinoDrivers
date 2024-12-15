#ifndef TMP_BUTTON_TIMED_HPP
#define TMP_BUTTON_TIMED_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonChanged.hpp"

#include <limits.h>
#include <stdint.h>
#include <string.h>

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
          ButtonTimedProperties::Duration_t DurationLong_,
          size_t HistoryLength_ = 2>
class ButtonTimed : public ButtonChanged<Button_>
{
    typedef ButtonChanged<Button_> BaseButton;

public:
//    static ButtonTimedProperties::Duration_t  constexpr DurationShort = DurationShort_;
//    static ButtonTimedProperties::Duration_t  constexpr DurationLong = DurationLong_;

    static_assert(0 < DurationShort_);
    static_assert(DurationShort_ < DurationLong_);
    static_assert(2 <= HistoryLength_);

    static void initialize()
    {
        BaseButton::initialize();
        memset(history_, 0, HistoryLength_);
        currentDuration_ = history_;
    }

    static void clearHistory()
    {
        memset(history_, 0, HistoryLength_);
    }

    static void update()
    {
        BaseButton::update();

        if (BaseButton::toggled())
        {
            currentDuration_ = otherDuration_(currentDuration_, true, 1);
            *currentDuration_ = 1;
        }
        else
        {
            // Only increase up to max of Duration_t - do not overflow!
            static_assert(UCHAR_MAX == static_cast<ButtonTimedProperties::Duration_t>(-1));
            if (UCHAR_MAX > *currentDuration_)
            {
                ++(*currentDuration_);
            }
        }
    }

    static ButtonTimedProperties::Duration currentState()
    {
        return durationToState_(*currentDuration_);
    }

    static ButtonTimedProperties::Duration previousState()
    {
        return durationToState_(*otherDuration_(currentDuration_, false, 1));
    }

    static ButtonTimedProperties::Duration previousState(size_t const offset)
    {
        return durationToState_(previousDuration_(offset));
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

protected:

    static ButtonTimedProperties::Duration_t previousDuration_(size_t const offset)
    {
        ButtonTimedProperties::Duration_t duration = 0;
        if (HistoryLength_ > offset)
        {
            duration = *otherDuration_(currentDuration_, false, offset);
        }
        else
        {
            // Keep 0 for offsets out of range.
        }
        return duration;
    }

    static ButtonTimedProperties::Duration durationToState_(ButtonTimedProperties::Duration_t const & duration)
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

private:
    static ButtonTimedProperties::Duration_t history_[HistoryLength_];
    static ButtonTimedProperties::Duration_t * currentDuration_;

    ButtonTimed() = delete;

    static ButtonTimedProperties::Duration_t * otherDuration_(
        ButtonTimedProperties::Duration_t * const currentDuration,
        bool const forward,
        size_t const offset)
    {
        // assert(currentDuration >= history_);
        // assert(currentDuration < (history_ + HistoryLength_));

        size_t const circularlyReducedOffset = offset % HistoryLength_;

        ButtonTimedProperties::Duration_t * otherDuration = nullptr;
        if (forward)
        {
            otherDuration = currentDuration + circularlyReducedOffset;
            if ((history_ + HistoryLength_) <= otherDuration)
            {
                otherDuration -= HistoryLength_;
            }
            else
            {
                // no underflow possible
            }
        }
        else
        {
            otherDuration = currentDuration - circularlyReducedOffset;
            if (history_ > otherDuration)
            {
                otherDuration += HistoryLength_;
            }
            else
            {
                // no overflow possible
            }
        }
        return otherDuration;
    }

};

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          size_t HistoryLength_>
ButtonTimedProperties::Duration_t ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_>::history_[HistoryLength_];

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          size_t HistoryLength_>
ButtonTimedProperties::Duration_t * ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_>::currentDuration_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_TIMED_HPP
