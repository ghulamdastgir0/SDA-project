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
// Note: Most destructors are now implemented in their respective *_Methods.cpp files

// Initialize static members
int InstructorRequest::requestID = 0;
int Schedule::scheduleID = 0;
int TimeSheet::timesheetID = 0;
