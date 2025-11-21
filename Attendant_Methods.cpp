#include "Attendant.h"
#include <iostream>

using namespace std;

Attendant::Attendant(string name, int buildingID, int attendantID) {
    // Initialize base Person fields via setters (Person implementation expected elsewhere)
    setId(attendantID);
    setName(name);
    this->buildingID = buildingID;
    cout << "Attendant '" << name << "' (ID=" << attendantID << ") assigned to building " << buildingID << " created." << endl;
}

Attendant::~Attendant() {
    cout << "Attendant with ID " << getId() << " destroyed." << endl;
}

void Attendant::setBuildingID(int id) {
    buildingID = id;
}

int Attendant::getBuildingID() const {
    return buildingID;
}

void Attendant::recordTimeSheetEntry(TimeSheet &entry) {
    // For now, just log the action. Real implementation should save to a TimeSheet manager.
    cout << "Attendant (ID=" << getId() << ") recording a timesheet entry for lab." << endl;
    // TODO: Integrate with central timesheet storage
}
