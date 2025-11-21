#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule() 
    : labID(0), dayOfWeek(0), isMakeup(false), time()
{
    cout << "Schedule created (default)." << endl;
}

Schedule::Schedule(int lab, int day, int weekNo, int startHr, int endHr, int startMin, int endMin)
    : labID(lab), dayOfWeek(day), isMakeup(false), time(startHr, startMin, endHr, endMin)
{
    cout << "Schedule created for Lab " << lab << " on day " << day << endl;
}

Schedule::~Schedule() {
    cout << "Schedule (Lab ID: " << labID << ") destroyed." << endl;
}

void Schedule::changeSchedule(int labID, int dayOfWeek, int weekNo,
    int startHr, int EndHr, int startMin, int endMin) {
    cout << "Schedule changed for Lab " << labID << endl;
    time.setStartTime(startHr, startMin);
    time.setEndTime(EndHr, endMin);
}
