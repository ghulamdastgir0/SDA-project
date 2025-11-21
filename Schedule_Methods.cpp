#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule()
    : labID(0), dayOfWeek(0), isMakeup(false), time()
{
}

Schedule::Schedule(int lab, int day, int weekNo, int startHr, int EndHr, int startMin, int endMin)
    : labID(lab), dayOfWeek(day), isMakeup(false), time()
{
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
    cout << "Schedule created for lab " << labID << " day " << dayOfWeek << "\n";
}

Schedule::~Schedule() {
}

void Schedule::changeSchedule(int lab, int day, int weekNo, int startHr, int EndHr, int startMin, int endMin) {
    labID = lab;
    dayOfWeek = day;
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
    cout << "Schedule changed for lab " << labID << " to day " << dayOfWeek << "\n";
}
