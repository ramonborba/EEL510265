#include <iostream>

#include "VMStateMachine.hpp"
#include "VMState.hpp"
#include "../Oled/Oled.h"

VMStateMachine::VMStateMachine() : currentState(nullptr) {}

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

VMStateMachine::Command VMStateMachine::requestCmd() {
    std::cout << "Requesting cmd...\n";

    // print msg in OLED
    Command cmd = Command::M025;
    // read inputs

    std::cout << "Received cmd: " << static_cast<int>(cmd) << "\n";
    return cmd;
}

VMStateMachine::Product VMStateMachine::requestProduct() {
    std::cout << "Requesting product...\n";
    // print msg in OLED
    Product prod = Product::MEET;
    // read inputs

    std::cout << "Selected product: " << static_cast<int>(prod) << "\n";
    return prod;
}

void VMStateMachine::deliverProduct(Product prod) {
    switch (prod) {
        case Product::MEET:
            std::cout << "Delivering MEET.\n";
            // set corresponding LED
            // print msg in OLED
            break;
        case Product::ETIRPS:
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
