#ifndef SIMPLE_PIN_DYNAMIC_HPP
#define SIMPLE_PIN_DYNAMIC_HPP

// ----------------------------------------------------------------------------------------------------

#include "simplePin.hpp"




typedef void (*InitSimplePinFunction_t)(void const * const instance);
typedef SimplePin::State (*GetSimplePinIsDown_t)(void const * const instance);
typedef void (*SetSimplePinIsDown_t)(void const * const instance, SimplePin::State const state);
typedef void (*DeinitSimplePinFunction_t)(void const * const instance);


/** SimplePinDynamic provides a way to access SimplePin TMP-classes via run-time [i.e. dynamic] instances.
  *
  * SimplePinDynamic uses it's own address as an "index".
  *
  * This occupies down to 1 byte per instance in RAM, requires however additional flash and runtime. As
  * for microcontrollers RAM is the most constrained entity, this design was chosen.
  *
  * It's usage is designed similar to the following:
  *
  * SimplePinDynamic<...> simplePins[3] = {
  *     {},
  *     {},
  *     {},
  * };
  *
  * void simplePinInitialize(void const * const instance)
  * {
  *     switch (static_cast<SimplePinDynamic<...> const *>(instance) - simplePins)
  *     {
  *     case 0: return SimplePin0::initialize();
  *     case 1: return SimplePin1::initialize();
  *     case 2: return SimplePin2::initialize();
  *     }
  *     // assert(numberOfSimplePins > index);
  * }
  *
  **/
template<typename InitSimplePinFunction_t initSimplePinFunction,
         typename GetSimplePinIsDown_t getSimplePinIsDown,
         typename DeinitSimplePinFunction_t deinitSimplePinFunction>
class SimplePinReadDynamic
{
public:

    constexpr SimplePinReadDynamic()
    {
        initSimplePinFunction(this);
    }

    ~SimplePinReadDynamic()
    {
        deinitSimplePinFunction(this);
    }

    /**
     * @brief get - SimplePin is currently being pressed down.
     */
    SimplePin::State get()
    {
        return getSimplePinIsDown(this);
    }

};

template<typename InitSimplePinFunction_t initSimplePinFunction,
         typename GetSimplePinIsDown_t getSimplePinIsDown,
         typename SetSimplePinIsDown_t setSimplePinIsDown,
         typename DeinitSimplePinFunction_t deinitSimplePinFunction>
class SimplePinDynamic
    : public SimplePinReadDynamic<initSimplePinFunction, getSimplePinIsDown, deinitSimplePinFunction>
{
public:

    /**
     * @brief isDown - SimplePin is currently being pressed down.
     */
    void set(SimplePin::State const state)
    {
        return setSimplePinIsDown(this, state);
    }

};

// ----------------------------------------------------------------------------------------------------

#endif // SIMPLE_PIN_DYNAMIC_HPP
