#ifndef TMP_BUTTON_TIMED_MULTIPLE_HPP
#define TMP_BUTTON_TIMED_MULTIPLE_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonTimed.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename Button_,
          ButtonTimedProperties::Duration_t DurationShort_,
          ButtonTimedProperties::Duration_t DurationLong_,
          ButtonTimedProperties::Duration_t DurationCombineMax_,
          size_t HistoryLength_ = 5>
class ButtonTimedMultiple : public ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_>
{
    typedef ButtonTimed<Button_, DurationShort_, DurationLong_, HistoryLength_> BaseButton;

public:

    static_assert(DurationShort_ <= DurationCombineMax_);
    static_assert(4 < HistoryLength_);

    // convenience access methods

    static bool isDownDoubleShortFinished()
    {
        return (BaseButton::isDown() &&
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(1)) &&
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(2)) &&
                (DurationShort_ <= ButtonTimedMultiple::previousDuration_(3)) &&
                (DurationCombineMax_ >= ButtonTimedMultiple::previousDuration_(3)) &&
                (ButtonTimedProperties::Duration::Short == ButtonTimedMultiple::previousState(4)));
    }

private:

    ButtonTimedMultiple() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_TIMED_MULTIPLE_HPP
