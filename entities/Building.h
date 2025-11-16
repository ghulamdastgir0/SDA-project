#pragma once
#include "Room.h"
#include "Attendant.h"
class Building {
public:
    int buildingID;
    char buildingName[30];
    Attendant attendant;
    Room* rooms;
};
