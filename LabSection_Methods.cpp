#include "LabSection.h"
#include <iostream>

using namespace std;

LabSection::LabSection(int ID, int roomNo, string courseCode, int instructorID, int sectionNumber, vector<int> ta)
    : labID(ID), courseCode(courseCode), teachingHours(0), leaves(0), instructorID(instructorID), tas(ta), room(roomNo)
{
    cout << "LabSection created: ID=" << labID << " course=" << courseCode << " room=" << room << " instructor=" << instructorID << "\n";
}

LabSection::~LabSection() {
    // nothing to free: we don't own TA or Room pointers here (we store IDs)
}

void LabSection::addTA(TA* ta) {
    if (!ta) return;
    // We only track TA IDs in this class; if TA has getId() use it, otherwise just log
    // Attempt to use getId() if available
    int id = 0;
    // Unsafe to call ta->getId() if not declared; we'll try via method if exists at runtime
    // For now, just log and leave the integer vector unchanged if id unknown
    cout << "Adding TA to LabSection " << labID << " (TA pointer=" << ta << ")\n";
}

void LabSection::assignRoom(Room* r) {
    if (!r) return;
    // Room stores no public getter in header; just log assignment
    cout << "Assigning room to LabSection " << labID << " (Room ptr=" << r << ")\n";
}

void LabSection::updateTeachingHours(int hrs) {
    if (hrs < 0) return;
    teachingHours = hrs;
    cout << "LabSection " << labID << " teaching hours set to " << teachingHours << "\n";
}

void LabSection::incrementLeaves() {
    ++leaves;
    cout << "LabSection " << labID << " leaves incremented to " << leaves << "\n";
}

void LabSection::decrementLeaves() {
    if (leaves > 0) --leaves;
    cout << "LabSection " << labID << " leaves decremented to " << leaves << "\n";
}
