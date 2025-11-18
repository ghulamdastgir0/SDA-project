#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include "Schedule.h"
#include "TimeSheet.h"
#include "LabSection.h"

class HeadOfDepartment : public Person {
public:
    HeadOfDepartment();
    ~HeadOfDepartment();

    vector<Schedule> getCompleteWeeklySchedule(int weekNumber) const;

    vector<TimeSheet> getFilledTimeSheetsForWeek(int weekNumber) const;

    vector<TimeSheet> getTimeSheetsForLab(int labId) const;
    
    double computeTotalContactHoursForLab(int labId) const;
    int computeLeavesForLab(int labId) const;

private:
    vector<int> managedLabIds;
};