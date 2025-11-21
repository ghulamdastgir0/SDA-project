#include "Building.h"
#include "Attendant.h"
#include <iostream>
#include <vector>

using namespace std;

Building::Building()
    : buildingID(0), buildingName(""), attendantID(-1), rooms()
{
    // default constructor
}

Building::Building(int ID, const string& name, int attID)
    : buildingID(ID), buildingName(name), attendantID(attID), rooms()
{
}

Building::~Building()
{
    // Do not delete Room* pointers here — ownership not specified.
    rooms.clear();
}

int Building::getID() {
    return buildingID;
}

void Building::setID(int ID) {
    buildingID = ID;
}

Attendant* Building::getAttendant() {
    // We only store attendant ID in this class. There is no global registry
    // available here to resolve the ID to an Attendant*; return nullptr for now.
    return nullptr;
}

void Building::setAttendant(Attendant* att) {
    if (att) attendantID = att->getId();
    else attendantID = -1;
}
