#include "WeeklyTimesheetReport.h"
#include <iostream>

WeeklyTimesheetReport::WeeklyTimesheetReport(LabManagementSystem *system, int weekNumber)
    : Report(system), m_weekNumber(weekNumber) {}

WeeklyTimesheetReport::~WeeklyTimesheetReport() {}

void WeeklyTimesheetReport::generate() {
    std::cout << "[Report] Generating weekly timesheet report for week " << m_weekNumber << std::endl;
}

int WeeklyTimesheetReport::getWeekNumber() const { 
    return m_weekNumber; 
}
