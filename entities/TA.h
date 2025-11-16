#pragma once
#include "Person.h"
#include "LabSection.h"
class TA : public Person {
    LabSection* assignedLabs;
    int assignedLabCount;
};