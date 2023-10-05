#ifndef _OLED_CLASS_HPP_
#define _OLED_CLASS_HPP_

class OledDisplay {
public:
    OledDisplay();
    ~OledDisplay();

    void printWelcomeScreen();
    void printRequestCmd(int total);
    void printRequestProduct();
    void printMsg(char* msg);
};

#endif /* _OLED_CLASS_HPP_ */