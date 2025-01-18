#ifndef BUTTON_TIMED_PROPERTIES_HPP
#define BUTTON_TIMED_PROPERTIES_HPP

// ----------------------------------------------------------------------------------------------------

#include <stdint.h>

// ----------------------------------------------------------------------------------------------------

namespace ButtonTimedProperties
{

typedef uint8_t Duration_t; // in number of update() calls [must be unsigned, see update()]

enum class Duration
{
    TooShort,
    Short,
    Long
};

} // namespace ButtonTimedProperties

// ----------------------------------------------------------------------------------------------------

#endif // BUTTON_TIMED_PROPERTIES_HPP
