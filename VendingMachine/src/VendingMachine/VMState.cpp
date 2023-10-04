#include <iostream>

#include "VMState.hpp"
#include "VMStateMachine.hpp"

void S000::enter( VMStateMachine* sm ) {
    std::cout << "Entering S000;\n";
}

void S000::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S025::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->setState(S050::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->setState(S100::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(0);
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
    return;
}

void S000::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S000;\n";
}

void S025::enter( VMStateMachine* sm ) {
    std::cout << "Entering S025;\n";
}

void S025::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S050::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->setState(S075::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->setState(S125::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(25);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
    return;
}

void S025::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S025;\n";
}

void S050::enter( VMStateMachine* sm ) {
    std::cout << "Entering S050;\n";
}

void S050::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S075::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->setState(S100::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(50);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
}

void S050::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S050;\n";
}

void S075::enter( VMStateMachine* sm ) {
    std::cout << "Entering S075;\n";
}

void S075::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S100::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->setState(S125::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->returnChange(25);
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(75);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
    return;
}

void S075::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S075;\n";
}

void S100::enter( VMStateMachine* sm ) {
    std::cout << "Entering S100;\n";
}

void S100::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S125::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->returnChange(50);
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(100);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
    return;
}

void S100::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S100;\n";
}

void S125::enter( VMStateMachine* sm ) {
    std::cout << "Entering S125;\n";
}

void S125::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::M050:
            sm->returnChange(25);
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::M100:
            sm->returnChange(75);
            sm->setState(S150::getInstance());
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(125);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            sm->noMoneyMsg();
            break;
    }
    return;
}

void S125::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S125;\n";
}

void S150::enter( VMStateMachine* sm ) {
    std::cout << "Entering S150;\n";
}

void S150::execute( VMStateMachine* sm ) {
    VMStateMachine::Command cmd = sm->requestCmd();
    switch (cmd) {
        case VMStateMachine::Command::M025:
            sm->returnChange(25);
            break;

        case VMStateMachine::Command::M050:
            sm->returnChange(50);
            break;

        case VMStateMachine::Command::M100:
            sm->returnChange(100);
            break;

        case VMStateMachine::Command::DEV:
            sm->returnChange(150);
            sm->setState(S000::getInstance());
            break;

        case VMStateMachine::Command::BUY:
            VMStateMachine::Product prod = sm->requestProduct();
            sm->deliverProduct(prod);
            sm->setState(S000::getInstance());
            break;
    }
    return;
}

void S150::exit( VMStateMachine* sm ) {
    std::cout << "Exiting S150;\n";
}

