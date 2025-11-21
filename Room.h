#pragma once

#include <string>
using namespace std;

class Room {
private:
    int roomID;
    int capacity;
    string roomNumber;
    int buildingID;
public:
    Room(int ID, int cap, const string& number, int bID);
    ~Room();

    int getID() const;
    int getCapacity() const;
    string getRoomNumber() const;
    int getBuildingID() const;
};
