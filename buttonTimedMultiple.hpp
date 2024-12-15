#ifndef TMP_BUTTON_TIMED_MULTIPLE_HPP
#define TMP_BUTTON_TIMED_MULTIPLE_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonTimed.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          ButtonTimedProperties::Duration_t DurationCombineMax_,
          size_t HistoryLength_ = 4>
class ButtonTimedMultiple : public ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_>
{
    typedef ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_> BaseButton;

public:

    static_assert(DurationShort_ <= DurationCombineMax_);
    static_assert(4 <= HistoryLength_);

    // convenience access methods

    static bool isDoubleDownShortFinished()
    {
        return (BaseButton::isUp() &&
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(1)) &&
                (DurationShort_ <= ButtonTimedMultiple::previousDuration_(2)) &&
                (DurationCombineMax_ >= ButtonTimedMultiple::previousDuration_(2)) &&
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(3)));
    }

private:

    ButtonTimedMultiple() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_TIMED_MULTIPLE_HPP
