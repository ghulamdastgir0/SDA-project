#include "TimeSheet.h"
#include <iostream>

using namespace std;

TimeSheet::TimeSheet() 
    : labID(0), weekNumber(0), dayOfWeek(0), isMakeup(false), time()
{
    cout << "TimeSheet created (default)." << endl;
}

TimeSheet::TimeSheet(int lab, int dayOfWeek_, int weekNo, int startHr, int endHr, int startMin, int endMin)
    : labID(lab), weekNumber(weekNo), dayOfWeek(dayOfWeek_), isMakeup(false), time(startHr, startMin, endHr, endMin)
{
    cout << "TimeSheet created for Lab " << lab << " Week " << weekNo << endl;
}

TimeSheet::~TimeSheet() {
    cout << "TimeSheet (Lab ID: " << labID << ") destroyed." << endl;
}

void TimeSheet::setTime(int startHr, int EndHr, int startMin, int endMin) {
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
    cout << "TimeSheet time updated." << endl;
}
