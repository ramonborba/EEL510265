#include "Calendar.h"

Calendar::Calendar(int d, int m, int y) : day(d), month(m), year(y) {
}

Calendar::~Calendar() {
}

void Calendar::setCalendar(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

void Calendar::readCalendar(int& d, int& m, int& y) {
    d = day;
    m = month;
    y = year;
}

void Calendar::advance() {
    day++;
    if (day > 30) {
        day = 1;
        month ++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
}
