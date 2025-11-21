#include "Schedule.h"
#include <iostream>

using namespace std;

Schedule::Schedule() 
    : labSectionID(0), dayOfWeek(0), isMakeup(false), time()
{
    cout << "Schedule created (default)." << endl;
}

Schedule::Schedule(int labSecID, int day, int startHr, int endHr, int startMin, int endMin)
    : labSectionID(labSecID), dayOfWeek(day), isMakeup(false), time(startHr, startMin, endHr, endMin)
{
    cout << "Schedule created for LabSection " << labSecID << " on day " << day 
         << " (" << startHr <<":" << startMin << " - " << endHr << ":" << endMin << ")" << endl;
}

Schedule::~Schedule() {
    // Nothing to free
}

void Schedule::changeSchedule(int labSecID, int day, int startHr, int endHr, int startMin, int endMin) {
    labSectionID = labSecID;
    dayOfWeek = day;
    time.setStartTime(startHr, startMin);
    time.setEndTime(endHr, endMin);
    cout << "Schedule changed for LabSection " << labSectionID << endl;
}

int Schedule::getLabSectionID() const {
    return labSectionID;
}

int Schedule::getDayOfWeek() const {
    return dayOfWeek;
}

bool Schedule::getIsMakeup() const {
    return isMakeup;
}

const Timing& Schedule::getTiming() const {
    return time;
}

void Schedule::setIsMakeup(bool makeup) {
    isMakeup = makeup;
}
