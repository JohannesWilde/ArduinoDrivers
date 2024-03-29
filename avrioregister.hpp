#ifndef TMP_AVR_IO_REGISTER_HPP
#define TMP_AVR_IO_REGISTER_HPP

#include <stdint.h>
#include "avrinputoutput.hpp"
#include "avrinternalregister.hpp"

// ----------------------------------------------------------------------------------------------------

// template "methods" to check whether provided types are equal

// in case the template parameters differ, set value to -1
// in this case, is_same will try to initialize an array of size -1 and fail during compilation
template<typename T, typename U>
struct is_same_
{
    static constexpr int value = -1;
};

// in case both template parameters are the same, set the value to 1
// in this case, is_same will initialize an array of size 1 and not fail during compilation
template<typename T>
struct is_same_<T, T>
{
    static constexpr int value = 1;
};

// depending on whether T and U are the same type or not, this will not or will fail during compilation
// this method should be kept in this module, in order to know the failure context [otherwise the error
// message is rather uninformative]!
template<typename T, typename U>
struct is_same
{
    static const char unequalTypes[is_same_<T,U>::value];
};

// ----------------------------------------------------------------------------------------------------


// The actual register

template<typename PortRegister, typename DdrRegister, typename PinRegister>
struct AvrIoRegister
{
private:
    // all three registers should have the same RegisterType, thus choose one.
    is_same<typename PortRegister::RegisterType, typename PinRegister::RegisterType> sameTypesPortPin;
    is_same<typename PortRegister::RegisterType, typename DdrRegister::RegisterType> sameTypesPortDdr;

public:
    typedef typename DdrRegister::RegisterType RegisterType;
    typedef PortRegister Port;
    typedef DdrRegister Ddr;
    typedef PinRegister Pin;

    // ----------------------------------------------------------------------------------------------------

    // setType(PinType const pinType, uint8_t const bitMask) only set those bits, that are 0b1 in bitMask
    static void setType(AvrInputOutput::PinType const pinType, RegisterType const bitMask)
    {
        switch (pinType)
        {
        case AvrInputOutput::OutputHigh:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::setBitMask(bitMask);      // high
            break;
        case AvrInputOutput::OutputLow:
            DdrRegister::setBitMask(bitMask);       // output
            PortRegister::clearBitMask(bitMask);    // low
            break;
        case AvrInputOutput::Input:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::clearBitMask(bitMask);    // no pull-up
            break;
        case AvrInputOutput::InputPullup:
            DdrRegister::clearBitMask(bitMask);     // input
            PortRegister::setBitMask(bitMask);      // pull-up [PUD in MCUCR needs to be low]
            // break;
        }
    }

    // ----------------------------------------------------------------------------------------------------

    static void togglePort(RegisterType const bitMask)
    {
        // Newer AVRs can toggle a PORT pin by writing a 1 [HIGH] to the respective PIN pin.
        // For very old AVRs thus below method will have to be changed...
//        PortRegister::toggleBitMask(bitMask);
        PinRegister::setBitMask(bitMask);
    }

    static void setPort(RegisterType const bitMask)
    {
        PortRegister::setBitMask(bitMask);
    }

    static void clearPort(RegisterType const bitMask)
    {
        PortRegister::clearBitMask(bitMask);
    }

    static typename PortRegister::RegisterType readPort()
    {
        return PortRegister::readRegister();
    }

    // ----------------------------------------------------------------------------------------------------

    /**
     * @brief togglePin Toggle the pin register bitMask.
     * @param bitMask Bits which are 1 will be toggled.
     * Please note that this is probably not what you want.
     * Toggling means reading the respective register and writing
     * the opposite of the result back to the same register.
     * As writing 0 to Pin does nothing and writing 1 to Pin toggles
     * the corresponding Port for newer AVRs [and does nothing for
     * older ones], this effectively toggles the corresponding Port
     * depending on the current value at Pin [and is a no-op for
     * older AVRs].
     */
    static void togglePin(RegisterType const bitMask)
    {
        PinRegister::toggleBitMask(bitMask);
    }

    static void setPin(RegisterType const bitMask)
    {
        PinRegister::setBitMask(bitMask);
    }

    static void clearPin(RegisterType const bitMask)
    {
        PinRegister::clearBitMask(bitMask);
    }

    static typename PinRegister::RegisterType readPin()
    {
        return PinRegister::readRegister();
    }

    // ----------------------------------------------------------------------------------------------------

    static void toggleDdr(RegisterType const bitMask)
    {
        DdrRegister::toggleBitMask(bitMask);
    }

    static void setDdr(RegisterType const bitMask)
    {
        DdrRegister::setBitMask(bitMask);
    }

    static void clearDdr(RegisterType const bitMask)
    {
        DdrRegister::clearBitMask(bitMask);
    }

    static typename DdrRegister::RegisterType readDdr()
    {
        return DdrRegister::readRegister();
    }

    // ----------------------------------------------------------------------------------------------------
};

#endif // TMP_AVR_IO_REGISTER_HPP
