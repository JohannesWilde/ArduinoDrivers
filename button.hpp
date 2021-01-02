#ifndef TMP_BUTTON_HPP
#define TMP_BUTTON_HPP

// ----------------------------------------------------------------------------------------------------

#include <stdint.h>
#include "avrpin.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename AvrPin_,
          AvrInputOutput::PinState PinDownState_,
          bool PullupEnabled_>
class Button
{
public:
    typedef AvrPin_ Pin;
    static AvrInputOutput::PinState constexpr PinDownState = PinDownState_;
    static bool constexpr PullupEnabled = PullupEnabled_;

    static void initialize()
    {
        AvrPin_::setType(AvrInputOutput::getInputType<PullupEnabled_>());
        currentState_ = AvrPin_::readPin();
        previousState_ = currentState_;
    }

    static void deinitialize()
    {
        AvrPin_::setType(AvrInputOutput::PinType::Input);
    }

    static void update()
    {
        previousState_ = currentState_;
        currentState_ = AvrPin_::readPin();
    }

    /**
   * isDown - button is currently being pressed down.
   */
    static bool isDown()
    {
        return (PinDownState_ == currentState_);
    }

    /**
   * pressed - button was pressed.
   */
    static bool pressed()
    {
        return ((currentState_ != previousState_) && (PinDownState_ == currentState_));
    }

    /**
   * released - button was released.
   */
    static bool released()
    {
        return ((currentState_ != previousState_) && (PinDownState_ != currentState_));
    }

protected:
    static AvrInputOutput::PinState getCurrentState_()
    {
        return currentState_;
    }

    static AvrInputOutput::PinState getPreviousState_()
    {
        return previousState_;
    }


private:
    static AvrInputOutput::PinState currentState_;
    static AvrInputOutput::PinState previousState_;
};

// ----------------------------------------------------------------------------------------------------

template <typename AvrPin_, AvrInputOutput::PinState PinDownState_, bool PullupEnabled_>
AvrInputOutput::PinState Button<AvrPin_, PinDownState_, PullupEnabled_>::currentState_;

template <typename AvrPin_, AvrInputOutput::PinState PinDownState_, bool PullupEnabled_>
AvrInputOutput::PinState Button<AvrPin_, PinDownState_, PullupEnabled_>::previousState_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_HPP
