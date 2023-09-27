#ifndef _CALENDAR_
#define _CALENDAR_

class Calendar {
public:
    Calendar(int d, int m, int y);
    ~Calendar();
    void setCalendar(int d, int m, int y);
    void readCalendar(int& d, int& m, int& y);
    void advance();

protected:
    int day;
    int month;
    int year;
};

#endif /* _CALENDAR_ */
