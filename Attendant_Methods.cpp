#include "Attendant.h"
#include <iostream>

using namespace std;

Attendant::Attendant(string name, int buildingID, int attendantID) 
    : Person(attendantID, name), buildingID(buildingID)
{
    // Attendant created; quiet startup output for cleaner UI
}

Attendant::~Attendant() {
    // quiet destructor
}

void Attendant::setBuildingID(int id) {
    buildingID = id;
}

int Attendant::getBuildingID() const {
    return buildingID;
}

void Attendant::recordTimeSheetEntry(TimeSheet &entry) {
    // record handled via LabManagementSystem::recordTimeSheet
}
