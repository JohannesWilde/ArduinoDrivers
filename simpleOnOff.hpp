#ifndef TMP_SIMPLE_ON_OFF_HPP
#define TMP_SIMPLE_ON_OFF_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

namespace SimpleOnOffProperties
{

enum State
{
    On,
    Off
};

} // namespace SimpleOnOffProperties

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

    static void initialize()
    {
        SimplePinRead_::initialize();
    }

    static void deinitialize()
    {
        SimplePinRead_::deinitialize();
    }

    static SimpleOnOffProperties::State get()
    {
        return (OnState_ == SimplePinRead_::get()) ? SimpleOnOffProperties::State::On : SimpleOnOffProperties::State::Off;
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

    static void set(typename SimpleOnOffProperties::State const state)
    {
        SimplePin_::set( (SimpleOnOffProperties::State::On == state) ? OnState_ : SimplePin::other<OnState_>());
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
