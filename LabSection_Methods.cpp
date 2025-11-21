#include "LabSection.h"
#include <iostream>

using namespace std;

LabSection::LabSection(int sectionID, int labID, string courseCode, int instructorID, int taID, int roomNo)
    : sectionID(sectionID), labID(labID), courseCode(courseCode), teachingHours(0), leaves(0), 
      instructorID(instructorID), taID(taID), roomNo(roomNo)
{
    cout << "LabSection created: sectionID=" << sectionID << " labID=" << labID 
         << " course=" << courseCode << " room=" << roomNo << " instructor=" << instructorID 
         << " TA=" << taID << "\n";
}

LabSection::~LabSection() {
    // nothing to free: we don't own TA or Room pointers here (we store IDs)
}

void LabSection::addTA(TA* ta) {
    if (!ta) return;
    cout << "Adding TA to LabSection " << sectionID << " (TA pointer=" << ta << ")\n";
}

void LabSection::assignRoom(Room* r) {
    if (!r) return;
    cout << "Assigning room to LabSection " << sectionID << " (Room ptr=" << r << ")\n";
}

void LabSection::updateTeachingHours(int hrs) {
    if (hrs < 0) return;
    teachingHours = hrs;
    cout << "LabSection " << sectionID << " teaching hours set to " << teachingHours << "\n";
}

void LabSection::incrementLeaves() {
    ++leaves;
    cout << "LabSection " << sectionID << " leaves incremented to " << leaves << "\n";
}

void LabSection::decrementLeaves() {
    if (leaves > 0) --leaves;
    cout << "LabSection " << sectionID << " leaves decremented to " << leaves << "\n";
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

void LabSection::addSchedule(unique_ptr<Schedule> schedule) {
    schedules.push_back(move(schedule));
}

const vector<unique_ptr<Schedule>>& LabSection::getSchedules() const {
    return schedules;
}

int LabSection::getScheduleCount() const {
    return schedules.size();
}
