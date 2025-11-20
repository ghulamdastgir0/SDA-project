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
    int instructorID;
    vector<int> tas;
    int room;
public:
    LabSection();
    LabSection(int ID,int room, string courseCode,int instructorID, int sectionNumber, vector<int> ta);
    ~LabSection();

    void addTA(TA* ta);
    void assignRoom(Room* room);
    void updateTeachingHours(int hrs);
    void incrementLeaves();
    void decrementLeaves();
};
