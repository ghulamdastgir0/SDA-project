#include "WeeklyScheduleReport.h"
#include "LabManagementSystem.h"
#include <iostream>

WeeklyScheduleReport::WeeklyScheduleReport(LabManagementSystem *system, int weekNumber)
    : Report(system), m_weekNumber(weekNumber) {}

WeeklyScheduleReport::~WeeklyScheduleReport() {}

void WeeklyScheduleReport::generate() {
    std::cout << "==== Weekly Lab Schedule Report ====" << std::endl;
    std::cout << "Listing all scheduled lab sessions for the week." << std::endl;
    if (!m_system) {
        std::cout << "No system available to generate report." << std::endl;
        return;
    }
    auto schedules = m_system->getWeeklySchedule(m_weekNumber);
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    if (schedules.empty()) {
        std::cout << "No schedules found." << std::endl;
    } else {
        for (const auto &s : schedules) {
            std::cout << "LabSection: " << s.getLabSectionID()
                      << " | Day: " << dayNames[s.getDayOfWeek()]
                      << " | Time: ";
            s.getTiming().print();
            std::cout << std::endl;
        }
    }
    std::cout << "===================================\n" << std::endl;
}

int WeeklyScheduleReport::getWeekNumber() const { 
    return m_weekNumber; 
}
