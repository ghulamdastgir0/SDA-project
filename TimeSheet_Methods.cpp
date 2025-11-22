#include "TimeSheet.h"
#include <iostream>

using namespace std;

TimeSheet::TimeSheet() 
    : labID(0), weekNumber(0), dayOfWeek(0), time()
{
    // quiet: default timesheet created
}

TimeSheet::TimeSheet(int lab, int dayOfWeek_, int weekNo, int startHr, int endHr, int startMin, int endMin)
    : labID(lab), weekNumber(weekNo), dayOfWeek(dayOfWeek_), time(startHr, startMin, endHr, endMin)
{
    // quiet: timesheet created
}

TimeSheet::~TimeSheet() {
    // quiet destructor
}

void TimeSheet::setTime(int startHr, int EndHr, int startMin, int endMin) {
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
    // quiet
}
