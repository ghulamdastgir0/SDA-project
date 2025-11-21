#pragma once
#include "Instructor.h"
#include "Room.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <memory>

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
    vector<unique_ptr<Schedule>> schedules;
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
    
    void addSchedule(unique_ptr<Schedule> schedule);
    const vector<unique_ptr<Schedule>>& getSchedules() const;
    int getScheduleCount() const;
};
