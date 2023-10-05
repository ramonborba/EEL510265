#include <iostream>

#include "VMStateMachine.hpp"
#include "VMState.hpp"

#include "../Keyboard/Keyboard.hpp"
#include "../Utils/Utils.hpp"

VMStateMachine::VMStateMachine() : currentState(&S000::getInstance()) {}

void VMStateMachine::start() {
    currentState = &S000::getInstance();
}

void VMStateMachine::execute() {
    while (true) {
        currentState->execute(this);
        delay(1000000);
    }
}

void VMStateMachine::setState(VMState& nextState) {
    currentState->exit(this);
    currentState = &nextState;
    currentState->enter(this);
}

enum VMStateMachine::Command VMStateMachine::requestCmd() {
    std::cout << "Requesting cmd...\n";
    // print msg in OLED
    Command cmd = M025;

    // read inputs
    enum Keyboard::Key key = Keyboard::getInstance().waitKeyPress();
    switch (key) {
        case Keyboard::BTNU:
            cmd = BUY;
            break;
        
        case Keyboard::BTNL:
            cmd = M025;
            break;
        
        case Keyboard::BTND:
            cmd = DEV;
            break;
        
        case Keyboard::BTNR:
            cmd = M100;
            break;
        
        case Keyboard::BTNC:
            cmd = M050;
            break;
        
        default:
            cmd = DEV;
            break;
    }

    std::cout << "Received cmd: " << static_cast<int>(cmd) << "\n";
    return cmd;
}

enum VMStateMachine::Product VMStateMachine::requestProduct() {
    volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
    std::cout << "Requesting product...\n";
    // print msg in OLED
    Product prod = MEET;
    Keyboard::Key key = Keyboard::getInstance().waitKeyPress();
    switch (key) {
        case Keyboard::BTNL:
            prod = MEET;   
            break;
        case Keyboard::BTNR:
            prod = ETIRPS;
            break;
        default:
            prod = MEET;
            break;
    }
    // read inputs

    std::cout << "Selected product: " << static_cast<int>(prod) << "\n";
    return prod;
}

void VMStateMachine::deliverProduct(enum Product prod) {
    switch (prod) {
        case MEET:
            std::cout << "Delivering MEET.\n";
            // set corresponding LED
            // print msg in OLED
            break;
        case ETIRPS:
            std::cout << "Delivering ETIRPS.\n";
            // set corresponding LED
            // print msg in OLED
            break;
    }
}

void VMStateMachine::returnChange( int amount ) {
    std::cout << "Returning " << amount << "\n";
}

void VMStateMachine::noMoneyMsg() {
    std::cout << "Insufficient money.\n";
    // print msg in OLED
}
