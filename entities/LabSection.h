#pragma once
#include "Instructor.h"
#include "TA.h"
#include "Room.h"
#include <string>

class LabSection {
private:
    int labID;
    string courseCode;
    int sectionNumber;
    int teachingHours;
    int leaves;
    Instructor* instructor;
    vector<TA*> tas;
    Room* room;
public:
    LabSection();
    LabSection(int ID,Room* room, string courseCode,Instructor* instr, vector<TA*> ta);
    ~LabSection();

    void addTA(TA* ta);
    void assignRoom(Room* room);
    void updateTeachingHours(int hrs);
    void incrementLeaves();
    void decrementLeaves();
};
