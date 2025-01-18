#ifndef BUTTON_DYNAMIC_HPP
#define BUTTON_DYNAMIC_HPP

// ----------------------------------------------------------------------------------------------------

/** ButtonDynamic uses it's own address as an "index".
  *
  * This saves at least 1 byte per instance in RAM, requires however additional flash and runtime. As
  * for microcontrollers RAM is the most constrained entity, this design was chosen.
  *
  * It's usage is designed similar to the following:
  *
  * ButtonDynamic<...> buttons[3] = {
  *     {},
  *     {},
  *     {},
  * };
  *
  * void buttonInitialize(void const * const instance)
  * {
  *     switch (static_cast<ButtonDynamic<...> const *>(instance) - buttons)
  *     {
  *     case 0: return Button0::initialize();
  *     case 1: return Button1::initialize();
  *     case 2: return Button2::initialize();
  *     }
  *     // assert(numberOfButtons > index);
  * }
  *
  **/
template<void (*initButtonFunction)(void const * const instance),
         bool (*getButtonIsDown)(void const * const instance),
         void (*deinitButtonFunction)(void const * const instance)>
class ButtonDynamic
{
public:

    constexpr ButtonDynamic()
    {
        initButtonFunction(this);
    }

    ~ButtonDynamic()
    {
        deinitButtonFunction(this);
    }

    /**
     * @brief isDown - button is currently being pressed down.
     */
    bool isDown() const
    {
        return getButtonIsDown(this);
    }

    /**
     * @brief isUp - button is currently not being pressed down.
     */
    bool isUp() const
    {
        return !isDown();
    }

};

// ----------------------------------------------------------------------------------------------------

#endif // BUTTON_DYNAMIC_HPP
