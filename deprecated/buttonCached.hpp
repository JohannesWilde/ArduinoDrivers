#ifndef TMP_BUTTON_CACHED_HPP
#define TMP_BUTTON_CACHED_HPP

// ----------------------------------------------------------------------------------------------------

/**
 * @brief The ButtonCache class monitors an actual button and provides state-change information.
 * Button will have to provide the following member function:   bool isDown()  .
 *
 */
template <typename Button>
class ButtonCached : public Button
{
public:
    // Button will have to be initialized externally for now!
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

private:
    static bool isDown_;

    ButtonCached() = delete;
};

// ----------------------------------------------------------------------------------------------------

template <typename Button>
bool ButtonCached<Button>::isDown_;

// ----------------------------------------------------------------------------------------------------

#endif // TMP_BUTTON_CACHED_HPP
