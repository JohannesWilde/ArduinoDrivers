
add_library(arduinoDrivers INTERFACE)

target_include_directories(arduinoDrivers
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..
)
