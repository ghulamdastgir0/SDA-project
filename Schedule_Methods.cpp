#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule() 
    : labSectionID(0), dayOfWeek(0), time()
{
    cout << "Schedule created (default)." << endl;
}

Schedule::Schedule(int labSecID, int day, int startHr, int endHr, int startMin, int endMin)
    : labSectionID(labSecID), dayOfWeek(day), time(startHr, startMin, endHr, endMin)
{
    cout << "Schedule created for Lab Section " << labSecID << " on day " << day << endl;
}

Schedule::~Schedule() {
    cout << "Schedule (Lab Section ID: " << labSectionID << ") destroyed." << endl;
}

void Schedule::changeSchedule(int labSectionID, int dayOfWeek,
    int startHr, int endHr, int startMin, int endMin) {
    cout << "Schedule changed for Lab Section " << labSectionID << endl;
    time.setStartTime(startHr, startMin);
    time.setEndTime(endHr, endMin);
}

int Schedule::getLabSectionID() const {
    return labSectionID;
}

int Schedule::getDayOfWeek() const {
    return dayOfWeek;
}

const Timing& Schedule::getTiming() const {
    return time;
}
