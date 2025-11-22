#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room(int ID, int cap, const string& number, int bID)
    : roomID(ID), capacity(cap), roomNumber(number), buildingID(bID)
{
    // suppressed: Room constructor output for cleaner UI
}

Room::~Room() {
    // nothing special
}

int Room::getID() const {
    return roomID;
}

int Room::getCapacity() const {
    return capacity;
}

string Room::getRoomNumber() const {
    return roomNumber;
}

int Room::getBuildingID() const {
    return buildingID;
}
