#include "Room.h"
#include <iostream>
#include <string>

using namespace std;

Room::Room(int ID, int cap, const string& number, int bID)
    : roomID(ID), capacity(cap), roomNumber(number), buildingID(bID)
{
    cout << "Room created: " << roomNumber << " (ID=" << roomID << ") capacity=" << capacity << " building=" << buildingID << "\n";
}

Room::~Room() {
    // nothing special
}
