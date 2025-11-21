#pragma once
#include "Room.h"
#include "Attendant.h"
#include <string>

class Building {
private:
    int buildingID;
    char buildingName[100];
    int attendantID;
    vector<Room*> rooms;
public:
    Building();
    Building(int ID, const char name[100], int attID);
    ~Building();

    int getID();
    void setID(int ID);

    Attendant* getAttendant();
    void setAttendant(Attendant* att);
};
