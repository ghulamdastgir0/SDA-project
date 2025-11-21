#include "TimeSheet.h"
#include <iostream>

using namespace std;

TimeSheet::TimeSheet(int lab, int dayOfWeek_, int weekNo, int startHr, int EndHr, int startMin, int endMin)
    : labID(lab), weekNumber(weekNo), dayOfWeek(dayOfWeek_), isMakeup(false), time()
{
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
    cout << "TimeSheet created for lab " << labID << " week " << weekNumber << " day " << dayOfWeek << "\n";
}

TimeSheet::~TimeSheet() {}

void TimeSheet::setTime(int startHr, int EndHr, int startMin, int endMin) {
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
}
