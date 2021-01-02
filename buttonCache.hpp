#ifndef TMP_BUTTON_CACHE_HPP
#define TMP_BUTTON_CACHE_HPP

// ----------------------------------------------------------------------------------------------------

#include "button.hpp"

// ----------------------------------------------------------------------------------------------------

template <typename Button_>
class ButtonCache
{
public:
    typedef Button_ Button;

    // Button_ will have to be initialized externally for now!
    static void initialize()
    {
        isDown_ = Button::isDown();
        update();
    }

    static void deinitialize()
    {
    }

    // if this is not called often enough, this will miss intermediate states
    static void update()
    {
        wasDown_ = isDown_;
        isDown_ = Button::isDown();
    }

    /**
     * @brief isDown - button is currently being pressed down.
     */
    static bool isDown()
    {
        return isDown_;
    }

    /**
     * @brief isUp - button is currently not being pressed down.
     */
    static bool isUp()
    {
        return !isDown();
    }

    /**
     * @brief pressed - button was pressed.
     */
    static bool pressed()
    {
        return (isDown_ && !wasDown_);
    }

    /**
     * @brief released - button was released.
     */
    static bool released()
    {
        return (!isDown_ && wasDown_);
    }

private:
    static bool isDown_;
    static bool wasDown_;
};

// ----------------------------------------------------------------------------------------------------

template <typename Button_>
bool ButtonCache<Button_>::isDown_;

template <typename Button_>
bool ButtonCache<Button_>::wasDown_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_CACHE_HPP
