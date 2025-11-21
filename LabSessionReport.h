#pragma once

#include "Report.h"
#include "TimeSheet.h"
#include <string>

class LabSessionReport : public Report {
public:
    LabSessionReport(LabManagementSystem *system, int labId);
    ~LabSessionReport();

    // Generate time sheet report for all sessions of a particular lab,
    // including total contact hours and leaves
    void generate() override;

    int getLabId() const;

private:
    int m_labId;
};
