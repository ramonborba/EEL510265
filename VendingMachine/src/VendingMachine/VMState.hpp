#ifndef _VM_STATE_H_
#define _VM_STATE_H_

class VMStateMachine;

class VMState {
public:
    virtual void enter( VMStateMachine* sm ) = 0;
    virtual void execute( VMStateMachine* sm ) = 0;
    virtual void exit( VMStateMachine* sm ) = 0;
    virtual float getTotal() = 0;
    virtual ~VMState() {};

};

class S000 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 0; };
    static VMState& getInstance() {
        static S000 instance;
        return instance;
    };

private:
    S000() {};
    S000( const S000& );
    S000& operator= ( const S000& );
};

class S025 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 0.25; };
    static VMState& getInstance() {
        static S025 instance;
        return instance;
    };

private:
    S025() {};
    S025( const S025& );
    S025& operator= ( const S025& );
};

class S050 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 0.50; };
    static VMState& getInstance() {
        static S050 instance;
        return instance;
    };

private:
    S050() {};
    S050( const S050& );
    S050& operator= ( const S050& );
};

class S075 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 0.75; };
    static VMState& getInstance() {
        static S075 instance;
        return instance;
    };

private:
    S075() {};
    S075( const S075& );
    S075& operator= ( const S075& );
};

class S100 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 1.00; };
    static VMState& getInstance() {
        static S100 instance;
        return instance;
    };

private:
    S100() {};
    S100( const S100& );
    S100& operator= ( const S100& );
};

class S125 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 1.25; };
    static VMState& getInstance() {
        static S125 instance;
        return instance;
    };

private:
    S125() {};
    S125( const S125& );
    S125& operator= ( const S125& );
};

class S150 : public VMState {
public:
    void enter( VMStateMachine* sm );
    void execute( VMStateMachine* sm );
    void exit( VMStateMachine* sm );
    float getTotal() { return 1.50; };
    static VMState& getInstance() {
        static S150 instance;
        return instance;
    };

private:
    S150() {};
    S150( const S150& );
    S150& operator= ( const S150& );
};

#endif // !_VM_STATE_H_
