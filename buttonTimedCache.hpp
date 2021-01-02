#ifndef TMP_BUTTON_DURATION_CACHE_HPP
#define TMP_BUTTON_DURATION_CACHE_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonCache.hpp"
#include "buttonTimed.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename ButtonTimed_>
class ButtonTimedCache : public ButtonCache<ButtonTimed_>
{
public:
    typedef ButtonTimed_ ButtonTimed;
    static ButtonTimedProperties::Duration_t  constexpr DurationShort = ButtonTimed_::DurationShort;
    static ButtonTimedProperties::Duration_t  constexpr DurationLong = ButtonTimed_::DurationLong;

    // ButtonTimed_ will have to be initialized externally for now!
    static void initialize()
    {
        ButtonCache<ButtonTimed_>::initialize();
        update();
    }

    static void update()
    {
        ButtonCache<ButtonTimed_>::update();
        currentState_ = ButtonTimed_::currentState();
        previousState_ = ButtonTimed_::previousState();
    }

    static ButtonTimedProperties::ButtonStateDuration currentState()
    {
        return currentState_;
    }

    static ButtonTimedProperties::ButtonStateDuration previousState()
    {
        return previousState_;
    }

    // convenience access methods

    static bool isDownShort()
    {
        return (ButtonCache<ButtonTimed_>::isDown() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == currentState()));
    }

    static bool isDownLong()
    {
        return (ButtonCache<ButtonTimed_>::isDown() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == currentState()));
    }

    static bool isUpShort()
    {
        return (ButtonCache<ButtonTimed_>::isUp() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == currentState()));
    }

    static bool isUpLong()
    {
        return (ButtonCache<ButtonTimed_>::isUp() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == currentState()));
    }

    static bool pressedAfterShort()
    {
        return (ButtonCache<ButtonTimed_>::pressed() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == previousState()));
    }

    static bool pressedAfterLong()
    {
        return (ButtonCache<ButtonTimed_>::pressed() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == previousState()));
    }

    static bool releasedAfterShort()
    {
        return (ButtonCache<ButtonTimed_>::released() &&
                (ButtonTimedProperties::ButtonStateDuration::Short == previousState()));
    }

    static bool releasedAfterLong()
    {
        return (ButtonCache<ButtonTimed_>::released() &&
                (ButtonTimedProperties::ButtonStateDuration::Long == previousState()));
    }


private:
    static ButtonTimedProperties::ButtonStateDuration currentState_;
    static ButtonTimedProperties::ButtonStateDuration previousState_;
};

// ----------------------------------------------------------------------------------------------------

template <typename ButtonTimed_>
ButtonTimedProperties::ButtonStateDuration ButtonTimedCache<ButtonTimed_>::currentState_;

template <typename ButtonTimed_>
ButtonTimedProperties::ButtonStateDuration ButtonTimedCache<ButtonTimed_>::previousState_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_DURATION_CACHE_HPP
