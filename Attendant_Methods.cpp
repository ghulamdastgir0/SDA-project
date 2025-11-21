#include "Attendant.h"
#include <iostream>

using namespace std;

Attendant::Attendant(string name, int buildingID, int attendantID) 
    : Person(attendantID, name), buildingID(buildingID)
{
    cout << "Attendant '" << name << "' (ID=" << attendantID << ") assigned to building " << buildingID << " created." << endl;
}

Attendant::~Attendant() {
    
}

void Attendant::setBuildingID(int id) {
    buildingID = id;
}

int Attendant::getBuildingID() const {
    return buildingID;
}

void Attendant::recordTimeSheetEntry(TimeSheet &entry) {
    cout << "Recording timesheet entry for Attendant " << getId() << endl;
}
