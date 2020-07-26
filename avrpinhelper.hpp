#ifndef TMP_AVR_PIN_HELPER_HPP
#define TMP_AVR_PIN_HELPER_HPP

// Helpers for even more convenient AvrPin handling.
template<typename AvrPin>
static void lowHighClock()
{
    AvrPin::clearPort();
    AvrPin::setPort();
}

template<typename AvrPin>
static void highLowClock()
{
    AvrPin::setPort();
    AvrPin::clearPort();
}

template<typename AvrPin>
static void toggleTwice()
{
    AvrPin::togglePort();
    AvrPin::togglePort();
}


#endif // TMP_AVR_PIN_HELPER_HPP
