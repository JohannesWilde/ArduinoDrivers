#ifndef TMP_AVR_DRIVER_HELPER_HPP
#define TMP_AVR_DRIVER_HELPER_HPP

/**
* @brief The DriverDeInitializer class provides a helper for
*  RAII-style initialization and deinitialization of driver classes.
* The DeviceDriver_ must support initialization via a static
*   initialize()
* method and deinitialization via a static
*   deinitialize()
* method.
* An instance of this class now takes care to deinitialize the
* DeviceDriver_ when this instance goes out of scope.
*/
template<typename DeviceDriver_>
class DriverDeInitializer
{
public:
    typedef DeviceDriver_ DeviceDriver;

    DriverDeInitializer()
    {
        DeviceDriver::initialize();
    }

    ~DriverDeInitializer()
    {
        DeviceDriver::deinitialize();
    }
};

#endif // TMP_AVR_DRIVER_HELPER_HPP
