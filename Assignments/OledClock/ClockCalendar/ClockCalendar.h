#ifndef _CLOCKCALENDAR_
#define _CLOCKCALENDAR_

#include "Clock.h"
#include "Calendar.h"

class ClockCalendar : public Clock, public Calendar {
public:
    ClockCalendar(int d, int mt, int y, int h, int m, int s, int pm);
    void advance();

private:
};

#endif /* _CLOCKCALENDAR_ */
