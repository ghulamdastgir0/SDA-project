#pragma once
#include "Person.h"
#include "LabSection.h"
#include "Request.h"
class Instructor : public Person {
    LabSection* assignedLabs;
    int assignedLabCount;
    InstructorRequest* requests;
    int requestCount;
};
