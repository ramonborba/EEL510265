#ifndef _KEYBOARD_HPP_
#define _KEYBOARD_HPP_

class Keyboard {
public:
    enum Key{
        NONE = 0,
        BTNU = 0b00001,
        BTNL = 0b00010,
        BTND = 0b00100,
        BTNR = 0b01000,
        BTNC = 0b10000,
    };
    
    enum Key waitKeyPress();

    static Keyboard& getInstance() {
        static Keyboard instance;
        return instance;
    }

private:
    
    volatile unsigned int* data;
    volatile unsigned int* output;
    volatile unsigned int* direction;
    
    enum Key readInputs();

    Keyboard();
    Keyboard(const Keyboard&);
    Keyboard& operator= (const Keyboard&);
};

#endif /* _KEYBOARD_HPP_ */