#include "ClockCalendar/ClockCalendar.h"
#include "Oled/Oled.h"

#include <string>
#include <sstream>


int main() {
	ClockCalendar cal (20, 9, 2023, 7, 16, 0, 1);

	oledInit();
	oledClear();
	
	int d, m, a;
	int hr, min, sec;
	bool pm;
	std::string time;
	std::ostringstream str;
	
	while(true) {
		oledClear();
		cal.readClock(hr, min, sec, pm);
		cal.readCalendar(d, m, a);
		setLine(0);
		printString((char*)"Data/Hora:");
		setLine(2);
		str.str("");
		str << d << "/" << m << "/" << a;
		printString((char*)str.str().c_str());
		setLine(3);
		str.str("");
		str << hr << ":" << min << ":" << sec << " " << (pm ? "PM" : "AM");
		printString((char*)str.str().c_str());
		delay(1000000);
		cal.advance();
	}

	return 0;
}
