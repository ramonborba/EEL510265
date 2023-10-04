#include <iostream>

#include "VMStateMachine.hpp"
#include "VMState.hpp"
#include "../Oled/Oled.h"

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
    volatile unsigned int *data = (volatile unsigned int *)0x80000a00;
    volatile unsigned int *direction = (volatile unsigned int *)0x80000a08;
    *direction = 0xffffffff;

    // print msg in OLED
    Command cmd = M025;
    // read inputs
    unsigned int input = 0;
    while (input == 0) {
        input = (*data >> 16) & (0b11111);
        delay(200000);
    }
    switch (input) {
        case 0b00001:
            cmd = BUY;
            break;
        
        case 0b00010:
            cmd = M025;
            break;
        
        case 0b00100:
            cmd = DEV;
            break;
        
        case 0b01000:
            cmd = M100;
            break;
        
        case 0b10000:
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
    unsigned int input = 0;
    while (input == 0) {
        input = (*data >> 16) & (0b11111);
        delay(200000);
    }
    Product prod = MEET;
    switch (input) {
        case 0b00001:
            prod = MEET;   
            break;
        case 0b00100:
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
