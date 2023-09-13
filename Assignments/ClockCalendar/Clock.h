class Clock {
public:
    Clock(int h, int m, int s, bool pm);
    ~Clock();
    void setClock(int h, int m, int s, bool pm);
    void readClock(int& h, int& m, int& s, bool& pm);
    void advance();

protected:
    int hr;    
    int min;    
    int sec;    
    bool isPM;
};
