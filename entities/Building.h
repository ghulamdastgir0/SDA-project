#pragma once
#include "Room.h"
#include "Attendant.h"
#include <string>

class Building {
private:
    int buildingID;
    string buildingName;
    Attendant* attendant;
    vector<Room*> rooms;
public:
    Building();
    Building(int ID);
    ~Building();

    int getID();
    void setID(int ID);

    Attendant* getAttendant();
    void setAttendant(Attendant* att);
};
