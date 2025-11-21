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
    // unique_ptr will automatically delete rooms
    rooms.clear();
}

void Building::addRoom(unique_ptr<Room> room) {
    rooms.push_back(move(room));
}

const vector<unique_ptr<Room>>& Building::getRooms() const {
    return rooms;
}

int Building::getRoomCount() const {
    return rooms.size();
}

int Building::getID() {
    return buildingID;
}

void Building::setID(int ID) {
    buildingID = ID;
}

string Building::getName() const {
    return buildingName;
}

int Building::getAttendantID() const {
    return attendantID;
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
