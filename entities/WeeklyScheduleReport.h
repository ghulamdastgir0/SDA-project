#pragma once

#include "Report.h"
#include "Schedule.h"
#include <string>

class WeeklyScheduleReport : public Report {
public:
    WeeklyScheduleReport(LabManagementSystem *system, int weekNumber);
    ~WeeklyScheduleReport();

    // Generate the complete lab schedule for the requested week
    void generate() override;

    int getWeekNumber() const;

private:
    int m_weekNumber;
};
