#include "Report.h"
#include "LabSessionReport.h"
#include <iostream>

// Base Report
Report::Report(LabManagementSystem *system)
    : m_system(system)
{
}

Report::~Report() {
}

// LabSessionReport
LabSessionReport::LabSessionReport(LabManagementSystem *system, int labId)
    : Report(system), m_labId(labId)
{
}

LabSessionReport::~LabSessionReport() {}

void LabSessionReport::generate() {
    std::cout << "[Report] Generating lab session report for lab " << m_labId << std::endl;
}

int LabSessionReport::getLabId() const { return m_labId; }
