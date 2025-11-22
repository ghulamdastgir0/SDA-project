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

// LabSessionReport is implemented in its own translation unit.
