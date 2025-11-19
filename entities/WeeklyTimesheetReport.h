#pragma once

#include "Report.h"
#include "TimeSheet.h"
#include <string>

class WeeklyTimesheetReport : public Report {
public:
    WeeklyTimesheetReport(LabManagementSystem *system, int weekNumber);
    ~WeeklyTimesheetReport();

    // Generate filled timesheets for all labs in the requested week
    void generate() override;

    int getWeekNumber() const;

private:
    int m_weekNumber;
};
