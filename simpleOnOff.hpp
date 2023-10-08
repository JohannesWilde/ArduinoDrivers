#ifndef TMP_SIMPLE_ON_OFF_HPP
#define TMP_SIMPLE_ON_OFF_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

/**
 * @brief Button interpretes simplePin values for button behaviour - readonly.
 */
template <typename SimplePinRead_,
         SimplePin::State OnState_>
class SimpleOnOffRead
{
public:
    typedef SimplePinRead_ Pin;
    //    static Pin::State constexpr OnState = OnState_;

    enum State
    {
        On,
        Off
    };

    static void initialize()
    {
        SimplePinRead_::initialize();
    }

    static void deinitialize()
    {
        SimplePinRead_::deinitialize();
    }

    static State get()
    {
        return (OnState_ == SimplePinRead_::get()) ? State::On : State::Off;
    }

private:

    SimpleOnOffRead() = delete;

};

// ----------------------------------------------------------------------------------------------------

/**
 * @brief Button interpretes simplePin values for button behaviour.
 */
template <typename SimplePin_,
         SimplePin::State OnState_>
class SimpleOnOff : public SimpleOnOffRead<SimplePin_, OnState_>
{
public:
    typedef SimplePin_ Pin;
    //    static Pin::State constexpr OnState = OnState_;
    typedef SimpleOnOffRead<SimplePin_, OnState_> Base;

    static void set(Base::State const state)
    {
        SimplePin_::set( (Base::State::On == state) ? OnState_ : SimplePin::other<OnState_>());
    }

    static void toggle()
    {
        SimplePin_::toggle();
    }

private:

    SimpleOnOff() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_ON_OFF_HPP
