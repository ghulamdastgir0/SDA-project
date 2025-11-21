#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include <memory>
#include "Schedule.h"
#include "TimeSheet.h"
#include "LabSection.h"
#include "Report.h"
#include "WeeklyScheduleReport.h"
#include "WeeklyTimesheetReport.h"
#include "LabSessionReport.h"

using namespace std;

class HeadOfDepartment : public Person {
    vector<int> managedLabIds;
public:
    // Construct with id, name and assigned lab section IDs
    HeadOfDepartment(int id, const string &name, const vector<int> &assignedLabSectionIDs);
    ~HeadOfDepartment();

    vector<int> getManagedLabIds() const;

    // Legacy data-access style (direct retrieval)
    vector<Schedule> getCompleteWeeklySchedule(int weekNumber) const;
    vector<TimeSheet> getFilledTimeSheetsForWeek(int weekNumber) const;
    vector<TimeSheet> getTimeSheetsForLab(int labId) const;

    double computeTotalContactHoursForLab(int labId) const;
    int computeLeavesForLab(int labId) const;

    // Report factory / helpers: create report objects which can be generated
    unique_ptr<Report> createWeeklyScheduleReport(int weekNumber);
    unique_ptr<Report> createWeeklyTimesheetReport(int weekNumber);
    unique_ptr<Report> createLabSessionReport(int labId);

    // Convenience: directly generate and output reports (delegates to report objects)
    void generateWeeklyScheduleReport(int weekNumber);
    void generateWeeklyTimesheetReport(int weekNumber);
    void generateLabSessionReport(int labId);
};
