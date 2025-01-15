#ifndef BUTTON_DYNAMIC_HPP
#define BUTTON_DYNAMIC_HPP

// ----------------------------------------------------------------------------------------------------

template<typename T,
         void (*initButtonFunction)(T const index),
         bool (*getButtonIsDown)(T const index),
         void (*deinitButtonFunction)(T const index)>
class ButtonDynamic
{
public:

    constexpr ButtonDynamic(T const index)
        : index_(index)
    {
        initButtonFunction(index_);
    }

    ~ButtonDynamic()
    {
        deinitButtonFunction(index_);
    }

    /**
     * @brief isDown - button is currently being pressed down.
     */
    bool isDown() const
    {
        return getButtonIsDown(index_);
    }

    /**
     * @brief isUp - button is currently not being pressed down.
     */
    bool isUp() const
    {
        return !isDown();
    }

private:
    T const index_;
};

// ----------------------------------------------------------------------------------------------------

#endif // BUTTON_DYNAMIC_HPP
