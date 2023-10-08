#ifndef TMP_SIMPLE_PIN_HPP
#define TMP_SIMPLE_PIN_HPP

// ----------------------------------------------------------------------------------------------------

/**
 * @brief The SimplePin class is the base for simplified access to a pin.
 *
 * All derived classes shall implement the following methods:
 *
 * setup:
 *    - static void initialize();
 *    - static void deinitialize();
 * 
 * input:
 *    - static State get();
 *
 * output [optional]:
 *    - static void set(State const state);
 *    - static void toggle();
 *
 */
class SimplePin
{
public:
    enum class State
    {
        Zero,
        One
    };

    template<State>
    static constexpr State other();

private:

    SimplePin() = delete;

};

// ----------------------------------------------------------------------------------------------------

template<>
constexpr SimplePin::State SimplePin::other<SimplePin::State::One>()
{
    return SimplePin::State::Zero;
}

template<>
constexpr SimplePin::State SimplePin::other<SimplePin::State::Zero>()
{
    return SimplePin::State::One;
}

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_PIN_HPP
