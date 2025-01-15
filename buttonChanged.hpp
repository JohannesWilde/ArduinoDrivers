#ifndef DYNAMIC_BUTTON_CHANGED_HPP
#define DYNAMIC_BUTTON_CHANGED_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonCached.hpp"

// ----------------------------------------------------------------------------------------------------

/**
 * @brief The ButtonChanged class provides convenience methods with additional info about a ButtonCached.
 * It tracks the previous state and can thus provide information as to the change that
 * occured between the second-to-last and last update() call.
 */
template <typename Button_, typename... Args>
class ButtonChanged : public ButtonCached<Button_, Args...>
{
    typedef ButtonCached<Button_, Args...> Button;

public:

    ButtonChanged(Args... args)
        : Button(args...)
        , wasDown_(Button::isDown())
    {
    }

    // if this is not called often enough, this will miss intermediate states
    void update()
    {
        wasDown_ = Button::isDown();
        Button::update();
    }

    /**
     * @brief pressed - button was pressed.
     */
    bool pressed() const
    {
        return (Button::isDown() && !wasDown_);
    }

    /**
     * @brief released - button was released.
     */
    bool released() const
    {
        return (!Button::isDown() && wasDown_);
    }

    bool toggled() const
    {
        return (Button::isDown() != wasDown_);
    }

private:

    bool wasDown_;

};

// ----------------------------------------------------------------------------------------------------

#endif // DYNAMIC_BUTTON_CHANGED_HPP
