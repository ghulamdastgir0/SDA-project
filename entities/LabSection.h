#pragma once
#include "Instructor.h"
#include "TA.h"
#include "Room.h"

class LabSection {
public:
    int labID;
    char courseCode[20];
    int sectionNumber;
    Instructor instructor;
    TA* tas;
    Room room;
};
