#ifndef DYNAMIC_BUTTON_CACHED_HPP
#define DYNAMIC_BUTTON_CACHED_HPP

// ----------------------------------------------------------------------------------------------------


/**
 * @brief The ButtonCache class monitors an actual button and provides state-change information.
 * Button will have to provide the following member function:
 *  - bool isDown(),
 *  - initialization [if any] in Button(args...),
 *  - deinitialization [if any] in ~Button().
 */
template <typename Button, typename... Args>
class ButtonCached : public Button
{
public:

    ButtonCached(Args... args)
        : Button(args...)
        , isDown_(Button::isDown())
    {
    }

    /**
     * @brief Updates the internal cache value with the current state of Button.
     * If this is not called often enough, intermediate states will be lost.
     */
    void update()
    {
        isDown_ = Button::isDown();
    }

    /**
     * @brief isDown - button was pressed down during last update().
     */
    bool isDown() const
    {
        return isDown_;
    }

    /**
     * @brief isDown - button was not pressed down during last update().
     */
    bool isUp() const
    {
        return !isDown();
    }

private:

    bool isDown_;

};

// ----------------------------------------------------------------------------------------------------

#endif // DYNAMIC_BUTTON_CACHED_HPP
