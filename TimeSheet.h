#pragma once
#include "Time.h"

class TimeSheet {
private:
    static int timesheetID;
    int labID;
    int weekNumber;
    int dayOfWeek;
    Timing time;

public:
    TimeSheet();
    TimeSheet(int labID, int dayOfWeek, int weekNo,
            int startHr, int EndHr, int startMin, int endMin);
    ~TimeSheet();

    void setTime(int startHr, int EndHr, int startMin, int endMin);
        int getLabID() const { return labID; }
        int getWeekNumber() const { return weekNumber; }
        int getDayOfWeek() const { return dayOfWeek; }
        const Timing& getTiming() const { return time; }
};
