#pragma once
#include "Instructor.h"
#include "Room.h"
#include <string>
#include <vector>

class TA;  // Forward declaration

class LabSection {
private:
    int labID;
    string courseCode;
    int teachingHours;
    int leaves;
    int instructorID;
    vector<int> tas;
    int room;
public:
    LabSection();
    LabSection(int ID, int room, string courseCode, int instructorID, int sectionNumber, vector<int> ta);
    ~LabSection();

    void addTA(TA* ta);
    void assignRoom(Room* room);
    void updateTeachingHours(int hrs);
    void incrementLeaves();
    void decrementLeaves();
};
