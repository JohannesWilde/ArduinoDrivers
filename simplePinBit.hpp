#ifndef TMP_SIMPLE_PIN_BIT_HPP
#define TMP_SIMPLE_PIN_BIT_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

/**
 * @brief PinBit simulates a HW pin via single bit in a byte - readonly.
 * Pleaes note that the referenced memory needs to be static, so its address can be passed as a
 * template parameter.
 * The bits are numbered from 0 to 7.
 */
template <uint8_t Bit_,
          uint8_t const & Byte_>
class SimplePinBitRead : public SimplePin
{
public:
//    static uint8_t constexpr Bit = Bit_;
//    static uint8_t * constexpr Byte_ = Byte_;
    static_assert(Bit_ < 8);

    static void initialize()
    {
        // intentionally empty
    }

    static void deinitialize()
    {
        // intentionally empty
    }

    static State get()
    {
        return ((Byte_ & bitMask_) == (0b1 << Bit_)) ? State::One : State::Zero;
    }

protected:

    static uint8_t constexpr bitMask_ = (0b1 << Bit_);

private:

    SimplePinBitRead() = delete;

};

// ----------------------------------------------------------------------------------------------------

/**
 * @brief PinBit simulates a HW pin via single bit in a byte.
 * Pleaes note that the referenced memory needs to be static, so its address can be passed as a
 * template parameter.
 * The bits are numbered from 0 to 7.
 */
template <uint8_t Bit_,
          uint8_t & Byte_>
class SimplePinBit : public SimplePinBitRead<Bit_, const_cast<uint8_t const &>(Byte_)>
{
public:
    typedef SimplePinBitRead<Bit_, const_cast<uint8_t const &>(Byte_)> Base;

    static void set(SimplePin::State const state)
    {
        switch (state)
        {
        case Base::State::Zero:
        {
            Byte_ &= ~Base::bitMask_;
            break;
        }
        case SimplePin::State::One:
        {
            Byte_ |= Base::bitMask_;
            break;
        }
        }
    }

    static void toggle()
    {
        Byte_ ^= Base::bitMask_;
    }

private:

    SimplePinBit() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_PIN_BIT_HPP
