#include "HeadOfDepartment.h"
#include "WeeklyScheduleReport.h"
#include "WeeklyTimesheetReport.h"
#include "LabSessionReport.h"
#include <iostream>

using namespace std;

  HeadOfDepartment::HeadOfDepartment(int id, const string &name, const vector<int> &assignedLabSectionIDs)
        : Person(id, name), managedLabIds(assignedLabSectionIDs)
    {
        cout << "HeadOfDepartment '" << name << "' (ID=" << id << ") initialized with " << managedLabIds.size() << " assigned lab sections." << endl;
    }

HeadOfDepartment::~HeadOfDepartment() {
    // cleanup if needed
}

vector<Schedule> HeadOfDepartment::getCompleteWeeklySchedule(int weekNumber) const {
    // Return empty vector for now; real implementation should query the system
    cout << "HOD: getCompleteWeeklySchedule(" << weekNumber << ") called." << endl;
    return {};
}

vector<TimeSheet> HeadOfDepartment::getFilledTimeSheetsForWeek(int weekNumber) const {
    cout << "HOD: getFilledTimeSheetsForWeek(" << weekNumber << ") called." << endl;
    return {};
}

vector<TimeSheet> HeadOfDepartment::getTimeSheetsForLab(int labId) const {
    cout << "HOD: getTimeSheetsForLab(" << labId << ") called." << endl;
    return {};
}

double HeadOfDepartment::computeTotalContactHoursForLab(int labId) const {
    cout << "HOD: computeTotalContactHoursForLab(" << labId << ") called." << endl;
    return 0.0;
}

int HeadOfDepartment::computeLeavesForLab(int labId) const {
    cout << "HOD: computeLeavesForLab(" << labId << ") called." << endl;
    return 0;
}

unique_ptr<Report> HeadOfDepartment::createWeeklyScheduleReport(int weekNumber) {
    // Create report with no system pointer for now
    return make_unique<WeeklyScheduleReport>(nullptr, weekNumber);
}

unique_ptr<Report> HeadOfDepartment::createWeeklyTimesheetReport(int weekNumber) {
    return make_unique<WeeklyTimesheetReport>(nullptr, weekNumber);
}

unique_ptr<Report> HeadOfDepartment::createLabSessionReport(int labId) {
    return make_unique<LabSessionReport>(nullptr, labId);
}

void HeadOfDepartment::generateWeeklyScheduleReport(int weekNumber) {
    auto r = createWeeklyScheduleReport(weekNumber);
    if (r) {
        r->generate();
    }
}

void HeadOfDepartment::generateWeeklyTimesheetReport(int weekNumber) {
    auto r = createWeeklyTimesheetReport(weekNumber);
    if (r) r->generate();
}

void HeadOfDepartment::generateLabSessionReport(int labId) {
    auto r = createLabSessionReport(labId);
    if (r) r->generate();
}
