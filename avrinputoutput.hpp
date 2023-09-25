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


    // convenience methods for access to respectively input or output only
    template<bool PullupEnabled_>
    AvrInputOutput::PinType getInputType()
    {
        return AvrInputOutput::PinType::Input;
    }

    template<PinState DesiredPinState_>
    AvrInputOutput::PinType getOutputType()
    {
        return AvrInputOutput::PinType::OutputLow;
    }

} // namespace AvrInputOutput


template<>
AvrInputOutput::PinType AvrInputOutput::getInputType</*PullupEnabled*/ true>()
{
    return AvrInputOutput::PinType::InputPullup;
}

template<>
AvrInputOutput::PinType AvrInputOutput::getOutputType</*DesiredPinState*/ AvrInputOutput::PinState::High>()
{
    return AvrInputOutput::PinType::OutputHigh;
}

#endif // TMP_AVR_INPUT_OUTPUT_HPP
