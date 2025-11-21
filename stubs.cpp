#include "Person.h"
#include "AcademicOfficer.h"
#include "Attendant.h"
#include "Instructor.h"
#include "TA.h"
#include "HeadOfDepartment.h"
#include "Building.h"
#include "Lab.h"
#include "LabSection.h"
#include "Schedule.h"
#include "TimeSheet.h"
#include "Request.h"

// Provide minimal destructor implementations and define static members

Person::~Person() {}

AcademicOfficer::~AcademicOfficer() {}
Attendant::~Attendant() {}
Instructor::~Instructor() {}
TA::~TA() {}
HeadOfDepartment::~HeadOfDepartment() {}

Building::~Building() {}
Lab::~Lab() {}
LabSection::~LabSection() {}
Room::~Room() {}

Schedule::~Schedule() {}
TimeSheet::~TimeSheet() {}
InstructorRequest::~InstructorRequest() {}

// Define static counters (single definition)
int Schedule::scheduleID = 0;
int InstructorRequest::requestID = 0;
int TimeSheet::timesheetID = 0;
