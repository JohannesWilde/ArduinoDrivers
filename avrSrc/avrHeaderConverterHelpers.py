import re
from os import path

if __name__ == "__main__":

    className = 'Atmega2560'
    registersNames = ('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'J', 'K', 'L')
    portNumbers = {'min': 0, 'max': 7}

    formString =\
"""
typedef AvrInternalRegister<SfrMemoryFromIoAddress<PORT{registerName}_REGISTER>::address, uint8_t> Port{registerName}Internal;
typedef AvrInternalRegister<SfrMemoryFromIoAddress<PIN{registerName}_REGISTER>::address, uint8_t> Pin{registerName}Internal;
typedef AvrInternalRegister<SfrMemoryFromIoAddress<DDR{registerName}_REGISTER>::address, uint8_t> Ddr{registerName}Internal;
typedef AvrIoRegister<Port{registerName}Internal, Ddr{registerName}Internal, Pin{registerName}Internal> Register{registerName};"""

    formString2 = """typedef AvrPin<Register{registerName}, PORT{registerName}{portNumber}> {registerName}{portNumber};"""
    #
    # for registerName in registersNames:
    #     print(formString.format(registerName=registerName))
    #     for portNumber in range(portNumbers['min'], portNumbers['max']+1):
    #         print(formString2.format(registerName=registerName, portNumber=portNumber))


    formString3 = 'typedef typename {className}::{registerName}{portNumber} ;'

    for registerName in registersNames:
        for portNumber in range(portNumbers['min'], portNumbers['max']+1):
            print(formString3.format(registerName=registerName, portNumber=portNumber, className=className))
        print('')  # newline

    exit(0)
