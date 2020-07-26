#ifndef AVRINPUTOUTPUT_HPP
#define AVRINPUTOUTPUT_HPP

// This namespace holds the enums for convenient HW I/O access

namespace AvrInputOutput
{
    enum PinType {
        OutputHigh,
        OutputLow,
        Input,
        InputPullup
    };

    // don't change these PinState-values, as they are the ones hardcoded in the
    // chip and currently not transformed in the reading methods.
    enum PinState {
        Low=0,
        High=1
    };
} // namespace AvrInputOutput

#endif // AVRINPUTOUTPUT_H
