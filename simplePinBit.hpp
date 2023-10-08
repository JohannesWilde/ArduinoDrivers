#ifndef TMP_SIMPLE_PIN_BIT_HPP
#define TMP_SIMPLE_PIN_BIT_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"

#include <stddef.h>
#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

/**
 * @brief PinBit simulates a HW pin via single bit in a byte - readonly.
 * Pleaes note that the referenced memory needs to be static, so its address can be passed as a
 * template parameter.
 * The bits are numbered from 0 to 7.
 */
template <uint8_t Bit_,
          uint8_t const * Byte_,
          size_t ByteOffset_ = 0>
class SimplePinBitRead : public SimplePin
{
public:
//    static uint8_t constexpr Bit = Bit_;
//    static uint8_t * constexpr Byte = Byte_;
//    static size_t constexpr ByteOffset = ByteOffset_;
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
        return ((value_() & bitMask_) == (0b1 << Bit_)) ? State::One : State::Zero;
    }

protected:

    static uint8_t constexpr bitMask_ = (0b1 << Bit_);

private:

    static inline uint8_t const & value_()
    {
        return *(Byte_ + ByteOffset_);
    }

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
         uint8_t * Byte_,
         size_t ByteOffset_ = 0>
class SimplePinBit : public SimplePinBitRead<Bit_, const_cast<uint8_t const *>(Byte_), ByteOffset_>
{
public:
    typedef SimplePinBitRead<Bit_, const_cast<uint8_t const *>(Byte_), ByteOffset_> Base;

    static void set(SimplePin::State const state)
    {
        switch (state)
        {
        case Base::State::Zero:
        {
            value_() &= ~Base::bitMask_;
            break;
        }
        case SimplePin::State::One:
        {
            value_() |= Base::bitMask_;
            break;
        }
        }
    }

    static void toggle()
    {
        value_() ^= Base::bitMask_;
    }

private:

    static inline uint8_t & value_()
    {
        return *(Byte_ + ByteOffset_);
    }

    SimplePinBit() = delete;

};

// ----------------------------------------------------------------------------------------------------

#endif // TMP_SIMPLE_PIN_BIT_HPP
