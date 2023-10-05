#include "Keyboard.hpp"
#include "../Utils/Utils.hpp"

const unsigned int GPIO_DATA_ADDR = 0x80000A00;
const unsigned int GPIO_OUTPUT_ADDR = 0x80000A04;
const unsigned int GPIO_DIR_ADDR = 0x80000A08;

Keyboard::Keyboard() : data { reinterpret_cast<volatile unsigned int*>(GPIO_DATA_ADDR) }, output { reinterpret_cast<volatile unsigned int*>(GPIO_DATA_ADDR) }, direction { reinterpret_cast<volatile unsigned int*>(GPIO_DATA_ADDR) } {
    *direction = 0xFFFFFFFF;
}

enum Keyboard::Key Keyboard::waitKeyPress() {
    enum Key keys = NONE;
    do
    {
        keys = readInputs();
        delay(200000);
    } while (keys == 0);
    
    return keys;
}

enum Keyboard::Key Keyboard::readInputs() {
    return static_cast<Key>((*data >> 16) & 0b11111);
}
