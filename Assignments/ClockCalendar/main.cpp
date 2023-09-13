#include <iostream>

#include "ClockCalendar.h"

void printClock(Clock clk) {
    int h, m, s;
    bool pm;
    clk.readClock(h, m, s, pm);
    std::cout << h << "h" << m << "m" << s << "s " << (pm ? "PM" : "AM") << "\n"; 
}

void printCalendar(Calendar cal) {
    int d, m, y;
    cal.readCalendar(d, m, y);
    std::cout << d << "/" << m << "/" << y << "\n"; 
}

int main (int argc, char *argv[]) {
    Clock clk (11, 59, 59, false);
    
    std::cout << "\n----- 11:59:59 AM to 12:00:00 PM ----- \n\n";
    printClock(clk);
    clk.advance();
    printClock(clk);
    clk.advance();
    printClock(clk);

    std::cout << "\n----- 11:59:59 PM to 00:00:00 AM ----- \n\n";
    clk.setClock(11, 59, 59, true);
    printClock(clk);
    clk.advance();
    printClock(clk);
    clk.advance();
    printClock(clk);

    Calendar cal (30, 12, 2023);
    std::cout << "\n----- Year Change ----- \n\n";
    printCalendar(cal);
    cal.advance();
    printCalendar(cal);
    cal.advance();
    printCalendar(cal);

    return 0;
}
