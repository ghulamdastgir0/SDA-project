#pragma once
#include "Time.h"
class Schedule {
private:
    static int scheduleID;
    int labID;
    int dayOfWeek;
    int weekNo;
    Timing time;
public:
    Schedule(int labID, int dayOfWeek, int weekNo,
            int startHr, int EndHr, int startMin, int endMin);
    Schedule();
    ~Schedule();

    void changeSchedule(int labID, int dayOfWeek, int weekNo,
    int startHr, int EndHr, int startMin, int endMin);
};