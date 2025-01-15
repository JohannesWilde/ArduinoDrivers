#ifndef DYNAMIC_BUTTON_TIMED_MULTIPLE_HPP
#define DYNAMIC_BUTTON_TIMED_MULTIPLE_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonTimed.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          ButtonTimedProperties::Duration_t DurationCombineMax_,
          size_t HistoryLength_ = 5,
          typename... Args>
class ButtonTimedMultiple : public ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_, Args...>
{
    typedef ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_, Args...> BaseButton;

public:

    static_assert(DurationShort_ <= DurationCombineMax_);
    static_assert(5 <= HistoryLength_);

    ButtonTimedMultiple(Args... args)
        : BaseButton(args...)
    {
        // intentionally empty
    }

    // convenience access methods

    bool isDoubleDownShortFinished()
    {
        return (BaseButton::isUp() &&
                // Current long enough not to potentially belong to the next one.
                ((DurationCombineMax_ + 1) == ButtonTimedMultiple::previousDuration_(0)) &&
                // Second short button press.
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(1)) &&
                // Intermediate not tooShort, but short enough to fit DurationCombineMax_.
                (DurationShort_ <= ButtonTimedMultiple::previousDuration_(2)) &&
                (DurationCombineMax_ >= ButtonTimedMultiple::previousDuration_(2)) &&
                // First short button press.
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(3)) &&
                // Rule out more than double press.
                ((DurationCombineMax_ < ButtonTimedMultiple::previousDuration_(4)) ||
                 (0 == ButtonTimedMultiple::previousDuration_(4)))
               );
    }

    bool isSingleDownShortFinished()
    {
        return (BaseButton::isUp() &&
                // Current long enough not to potentially belong to the next one.
                ((DurationCombineMax_ + 1) == ButtonTimedMultiple::previousDuration_(0)) &&
                // First short button press.
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(1)) &&
                // Rule out more than single press.
                ((DurationCombineMax_ < ButtonTimedMultiple::previousDuration_(2)) ||
                 (0 == ButtonTimedMultiple::previousDuration_(2)))
               );
    }

private:

};

// ----------------------------------------------------------------------------------------------------

#endif // DYNAMIC_BUTTON_TIMED_MULTIPLE_HPP
