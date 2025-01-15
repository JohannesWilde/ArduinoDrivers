#ifndef TMP_BUTTON_CHANGED_HPP
#define TMP_BUTTON_CHANGED_HPP

// ----------------------------------------------------------------------------------------------------

#include "buttonCached.hpp"

// ----------------------------------------------------------------------------------------------------

/**
 * @brief The ButtonChanged class provides convenience methods with additional info about a ButtonCached.
 * It tracks the previous state and can thus provide information as to the change that
 * occured between the second-to-last and last update() call.
 */
template <typename Button_>
class ButtonChanged : public ButtonCached<Button_>
{
    typedef ButtonCached<Button_> Button;

public:

    static void initialize()
    {
        Button::initialize();
        update();
    }

    static void deinitialize()
    {
        Button::deinitialize();
    }

    // if this is not called often enough, this will miss intermediate states
    static void update()
    {
        wasDown_ = Button::isDown();
        Button::update();
    }

    /**
     * @brief pressed - button was pressed.
     */
    static bool pressed()
    {
        return (Button::isDown() && !wasDown_);
    }

    /**
     * @brief released - button was released.
     */
    static bool released()
    {
        return (!Button::isDown() && wasDown_);
    }

    static bool toggled()
    {
        return (Button::isDown() != wasDown_);
    }

private:

    static bool wasDown_;

    ButtonChanged() = delete;

};

// ----------------------------------------------------------------------------------------------------

template <typename Button>
bool ButtonChanged<Button>::wasDown_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_CHANGED_HPP
