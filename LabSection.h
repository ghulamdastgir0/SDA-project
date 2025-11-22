#pragma once
#include "Instructor.h"
#include "Room.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class TA;  // Forward declaration

class LabSection {
private:
    int sectionID;
    int labID;
    string courseCode;
    int teachingHours;
    int leaves;
    int instructorID;
    int taID;
    int roomNo;
    unique_ptr<Schedule> schedule;
public:
    LabSection();
    LabSection(int sectionID, int labID, string courseCode, int instructorID, int taID, int roomNo);
    ~LabSection();

    void addTA(TA* ta);
    void assignRoom(Room* room);
    void updateTeachingHours(int hrs);
    void incrementLeaves();
    void decrementLeaves();

    int getSectionID() const;
    int getLabID() const;
    string getCourseCode() const;
    int getInstructorID() const;
    int getTAID() const;
    int getRoomNo() const;

    void setSchedule(std::unique_ptr<Schedule> schedule);
    const Schedule* getSchedule() const;
    int getScheduleCount() const; // returns 0 or 1
};
