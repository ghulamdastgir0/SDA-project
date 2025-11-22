#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule() 
    : labSectionID(0), dayOfWeek(0), time()
{
    // suppressed: default schedule created
}

Schedule::Schedule(int labSecID, int day, int startHr, int endHr, int startMin, int endMin)
    : labSectionID(labSecID), dayOfWeek(day), time(startHr, startMin, endHr, endMin)
{
    // suppressed: schedule created for lab section
}

Schedule::~Schedule() {
    // suppressed: schedule destroyed
}

void Schedule::changeSchedule(int labSectionID, int dayOfWeek,
    int startHr, int endHr, int startMin, int endMin) {
    // suppressed: schedule changed
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
