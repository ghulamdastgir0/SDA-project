#pragma once
#include "Time.h"
#include <memory>
#include <vector>
using namespace std;

class Schedule {
private:
    int labSectionID;
    int dayOfWeek;
    bool isMakeup;
    Timing time;
public:
    Schedule(int labSectionID, int dayOfWeek, int startHr, int endHr, int startMin, int endMin);
    Schedule();
    ~Schedule();

    void changeSchedule(int labSectionID, int dayOfWeek,
        int startHr, int endHr, int startMin, int endMin);
    
    int getLabSectionID() const;
    int getDayOfWeek() const;
    bool getIsMakeup() const;
    const Timing& getTiming() const;
    void setIsMakeup(bool makeup);
};