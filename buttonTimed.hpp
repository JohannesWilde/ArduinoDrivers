#ifndef DYNAMIC_BUTTON_TIMED_HPP
#define DYNAMIC_BUTTON_TIMED_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonChanged.hpp"
#include "buttonTimedProperties.hpp"

#include <limits.h>
#include <stdint.h>
#include <string.h>

// ----------------------------------------------------------------------------------------------------

/**
 * @brief The ButtonTimed class tracks the durations of HistoryLength_ previous states.
 * Intrinsically it has support for determining whether the last press was tooShort,
 * short or long.
 * For more info see ButtonTimedMultiple.
 */
template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          size_t HistoryLength_ = 2,
          typename... Args>
class ButtonTimed : public ButtonChanged<Button_, Args...>
{
    typedef ButtonChanged<Button_, Args...> BaseButton;

public:
    static_assert(0 < DurationShort_);
    static_assert(DurationShort_ < DurationLong_);
    static_assert(2 <= HistoryLength_);

    ButtonTimed(Args... args)
        : BaseButton(args...)
        , currentDuration_(history_)
    {
        clearHistory();
    }

    void clearHistory()
    {
        memset(history_, 0, HistoryLength_);
    }

    void update()
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

    ButtonTimedProperties::Duration currentState() const
    {
        return durationToState_(*currentDuration_);
    }

    ButtonTimedProperties::Duration previousState() const
    {
        return durationToState_(*otherDuration_(currentDuration_, false, 1));
    }

    ButtonTimedProperties::Duration previousState(size_t const offset) const
    {
        return durationToState_(previousDuration_(offset));
    }

    // convenience access methods

    bool isDownShort()
    {
        return (BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Short == currentState()));
    }

    bool isDownLong()
    {
        return (BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Long == currentState()));
    }

    bool isUpShort()
    {
        return (BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Short == currentState()));
    }

    bool isUpLong()
    {
        return (BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Long == currentState()));
    }

    bool pressedAfterShort()
    {
        return (BaseButton::pressed() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    bool pressedAfterLong()
    {
        return (BaseButton::pressed() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    bool releasedAfterShort()
    {
        return (BaseButton::released() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    bool releasedAfterLong()
    {
        return (BaseButton::released() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    bool wasDownShort()
    {
        return (!BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    bool wasDownLong()
    {
        return (!BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

    bool wasUpShort()
    {
        return (!BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Short == previousState()));
    }

    bool wasUpLong()
    {
        return (!BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Long == previousState()));
    }

protected:

    ButtonTimedProperties::Duration_t previousDuration_(size_t const offset) const
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
    ButtonTimedProperties::Duration_t history_[HistoryLength_];
    ButtonTimedProperties::Duration_t * currentDuration_;

    ButtonTimedProperties::Duration_t * otherDuration_(
        ButtonTimedProperties::Duration_t * const currentDuration,
        bool const forward,
        size_t const offset) const
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

#endif // DYNAMIC_BUTTON_TIMED_HPP
