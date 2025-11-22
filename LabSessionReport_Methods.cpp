#include "LabSessionReport.h"
#include "LabManagementSystem.h"
#include <iostream>

LabSessionReport::LabSessionReport(LabManagementSystem *system, int labId)
    : Report(system), m_labId(labId) {}

LabSessionReport::~LabSessionReport() {}

void LabSessionReport::generate() {
    std::cout << "[Report] Generating lab session report for lab " << m_labId << std::endl;
    if (!m_system) {
        std::cout << "No system available." << std::endl;
        return;
    }
    auto times = m_system->getTimeSheetsForLab(m_labId);
    double totalHours = m_system->computeTotalContactHoursForLab(m_labId);
    int leaves = m_system->computeLeavesForLab(m_labId);

    for (const auto &ts : times) {
        std::cout << "Week: " << ts.getWeekNumber() << " | Day: " << ts.getDayOfWeek() << " | Time: ";
        ts.getTiming().print();
        std::cout << std::endl;
    }
    std::cout << "Total contact hours (computed from schedules): " << totalHours << std::endl;
    std::cout << "Leaves: " << leaves << std::endl;
}

int LabSessionReport::getLabId() const {
    return m_labId;
}
