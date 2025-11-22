#include "LabSection.h"
#include <iostream>

using namespace std;

LabSection::LabSection()
    : sectionID(0), labID(0), courseCode(""), teachingHours(0), leaves(0), instructorID(0), taID(0), roomNo(0), schedule(nullptr)
{
}

LabSection::LabSection(int sectionID, int labID, string courseCode, int instructorID, int taID, int roomNo)
    : sectionID(sectionID), labID(labID), courseCode(courseCode), teachingHours(0), leaves(0), instructorID(instructorID), taID(taID), roomNo(roomNo), schedule(nullptr)
{
    // suppressed: LabSection creation output for cleaner UI
}

LabSection::~LabSection() {
    // unique_ptr will clean up schedule automatically
}

void LabSection::addTA(TA* ta) {
    if (!ta) return;
    // suppressed: add TA log
}

void LabSection::assignRoom(Room* r) {
    if (!r) return;
    // suppressed: assign room log
}

void LabSection::updateTeachingHours(int hrs) {
    if (hrs < 0) return;
    teachingHours = hrs;
    // suppressed: teaching hours update log
}

void LabSection::incrementLeaves() {
    ++leaves;
    // suppressed: leaves increment log
}

void LabSection::decrementLeaves() {
    if (leaves > 0) --leaves;
    // suppressed: leaves decrement log
}

int LabSection::getSectionID() const {
    return sectionID;
}

int LabSection::getLabID() const {
    return labID;
}

string LabSection::getCourseCode() const {
    return courseCode;
}

int LabSection::getInstructorID() const {
    return instructorID;
}

int LabSection::getTAID() const {
    return taID;
}

int LabSection::getRoomNo() const {
    return roomNo;
}

void LabSection::setSchedule(std::unique_ptr<Schedule> s) {
    schedule = std::move(s);
}

const Schedule* LabSection::getSchedule() const {
    return schedule.get();
}

int LabSection::getScheduleCount() const {
    return schedule ? 1 : 0;
}
