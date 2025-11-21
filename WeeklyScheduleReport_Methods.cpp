#include "WeeklyScheduleReport.h"
#include <iostream>

WeeklyScheduleReport::WeeklyScheduleReport(LabManagementSystem *system, int weekNumber)
    : Report(system), m_weekNumber(weekNumber) {}

WeeklyScheduleReport::~WeeklyScheduleReport() {}

void WeeklyScheduleReport::generate() {
    std::cout << "[Report] Generating weekly schedule report for week " << m_weekNumber << std::endl;
}

int WeeklyScheduleReport::getWeekNumber() const { 
    return m_weekNumber; 
}
