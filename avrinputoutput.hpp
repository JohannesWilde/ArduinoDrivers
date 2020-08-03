#ifndef TMP_AVR_INPUT_OUTPUT_HPP
#define TMP_AVR_INPUT_OUTPUT_HPP

// This namespace holds the enums for convenient HW I/O access

namespace AvrInputOutput
{
    enum PinType
    {
        OutputHigh,
        OutputLow,
        Input,
        InputPullup
    };

    // don't change these PinState-values, as they are the ones hardcoded in the
    // chip and currently not transformed in the reading methods.
    enum PinState
    {
        Low=0,
        High=1
    };
} // namespace AvrInputOutput

#endif // TMP_AVR_INPUT_OUTPUT_HPP
