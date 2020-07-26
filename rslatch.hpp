#ifndef TMP_RSLATCH_HPP
#define TMP_RSLATCH_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrpin.hpp"
#include "avrpinhelper.hpp"

template<typename SetPin_, typename ResetPin_, typename OutputEnablePin_>
// Set_, Reset_, OutputEnable_ - AvrPin types
struct RsLatch
{
public:
    typedef SetPin_ SetPin;
    typedef ResetPin_ ResetPin;
    typedef OutputEnablePin_ OutputEnablePin;

    static void initialize()
    {
        // set data directions of pins and default port states
        OutputEnablePin_::setType(AvrInputOutput::OutputLow);
        SetPin_::setType(AvrInputOutput::OutputLow);
        ResetPin_::setType(AvrInputOutput::OutputLow);
        reset();
    }

    static void turnOff()
    {
        OutputEnablePin_::clearPort();
        SetPin_::clearPort();
        reset();
    }


    static void turnOn()
    {
        turnOff();
    }

    static void enableOutput()
    {
        OutputEnablePin_::setPort();
    }

    static void disableOutput()
    {
        OutputEnablePin_::clearPort();
    }

    static void set()
    {
        highLowClock<SetPin_>();
    }

    static void reset()
    {
        highLowClock<ResetPin_>();
    }

};

#endif // TMP_RSLATCH_HPP
