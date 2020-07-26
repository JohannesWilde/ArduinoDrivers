import re
from os import path

"""
Additional to convenient register access via preprocessor defines,
    "#define DDRB    _SFR_IO8(0x04)"
provide the following separate information [additionally to the original content]:
    "#define DDRB_REGISTER 0x04
     #define DDRB_TYPE uint8_t
     #define DDRB_ACCESS _SFR_IO8
     #define DDRB DDRB_ACCESS(DDRB_REGISTER)"
.
This means that this script's output is fully backward compatible.


Copy the modified register definitions header to a subdirectory similar to the real sources [avr/...], as to let the
include be replaced with this customized version even when including io.h.
Please note, that in order for that to work, this submodule will have to be added to the CMake include directories first
[include_directories(${PROJECT_SOURCE_DIR}/ArduinoDrivers)].

Alternatively one can replace the original files [e.g. in /usr/share/arduino/hardware/tools/avr/lib/avr/include/avr].
"""

if __name__ == "__main__":
    filepath = "./iom328p.h"

    conversionMacros = ["_SFR_MEM", "_SFR_IO"]
    regularExpressions = [re.compile("#define\s*(.*?)\s*({conversionMacro})(\d+)\\((0x[0-9A-Fa-f]+)\\)".format(**{"conversionMacro": macro}))
                                                                                        for macro in conversionMacros]
    filenameParts = path.splitext(path.basename(filepath))
    outputFilename = "{filename}_converted{fileextension}".format(**{"filename": filenameParts[0], "fileextension": filenameParts[1]})
    with open(filepath, "r") as file, open(outputFilename, "w") as outputFile:
        for line in file:
            for regularExpression in regularExpressions:
                line = re.sub(regularExpression, "#define \\1_REGISTER \\4\n#define \\1_TYPE uint\\3_t\n#define \\1_ACCESS"
                                                 " \\2\\3\n#define \\1 \\1_ACCESS(\\1_REGISTER)", line)
            outputFile.write(line)


    exit(0)


