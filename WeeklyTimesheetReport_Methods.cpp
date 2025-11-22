#include "WeeklyTimesheetReport.h"
#include "LabManagementSystem.h"
#include <iostream>
#include <map>
#include <vector>

WeeklyTimesheetReport::WeeklyTimesheetReport(LabManagementSystem *system, int weekNumber)
    : Report(system), m_weekNumber(weekNumber) {}

WeeklyTimesheetReport::~WeeklyTimesheetReport() {}

void WeeklyTimesheetReport::generate() {
    std::cout << "==== Weekly Timesheet Report ====" << std::endl;
    std::cout << "Filled timesheets for week: " << m_weekNumber << std::endl;
    if (!m_system) {
        std::cout << "No system available to generate timesheet report." << std::endl;
        return;
    }
    auto times = m_system->getFilledTimeSheetsForWeek(m_weekNumber);
    if (times.empty()) {
        std::cout << "No filled timesheets found for this week." << std::endl;
    } else {
        // group by lab id
        std::map<int, std::vector<TimeSheet>> byLab;
        for (const auto &ts : times) byLab[ts.getLabID()].push_back(ts);
        for (const auto &p : byLab) {
            std::cout << "\nLab ID: " << p.first << "\n";
            for (const auto &ts : p.second) {
                std::cout << "  Week: " << ts.getWeekNumber() << " | Day: " << ts.getDayOfWeek() << " | Time: ";
                ts.getTiming().print();
                std::cout << std::endl;
            }
        }
    }
    std::cout << "===========================\n" << std::endl;
}

int WeeklyTimesheetReport::getWeekNumber() const { 
    return m_weekNumber; 
}
