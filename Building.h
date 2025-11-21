#pragma once
#include "Room.h"
#include "Attendant.h"
#include <string>

class Building {
private:
    int buildingID;
    string buildingName;
    int attendantID;
    vector<Room*> rooms;
public:
    Building();
    Building(int ID, const string& name, int attID);
    ~Building();

    int getID();
    void setID(int ID);

    Attendant* getAttendant();
    void setAttendant(Attendant* att);
};
