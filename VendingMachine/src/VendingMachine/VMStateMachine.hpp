#ifndef _VM_STATE_MACHINE_H_
#define _VM_STATE_MACHINE_H_

class VMState;

class VMStateMachine {
public:
    VMStateMachine();

    enum Command {
        M025,
        M050,
        M100,
        DEV,
        BUY,
    };

    enum Product {
        MEET,
        ETIRPS,
    };

    void start();
    void execute();
    void setState( VMState &nextState );

    Command requestCmd();
    Product requestProduct();
    void deliverProduct( Product prod );
    void returnChange( int amount );
    void noMoneyMsg();

private:
    VMState* currentState;
};

#endif // !_VM_STATE_MACHINE_H_
