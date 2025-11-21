#pragma once
#include "Room.h"
#include "Attendant.h"
#include <string>
#include <vector>
#include <memory>

using namespace std;

class Building {
private:
    int buildingID;
    string buildingName;
    int attendantID;
    vector<unique_ptr<Room>> rooms;
public:
    Building();
    Building(int ID, const string& name, int attID);
    ~Building();

    int getID();
    void setID(int ID);

    string getName() const;
    int getAttendantID() const;

    void addRoom(unique_ptr<Room> room);
    const vector<unique_ptr<Room>>& getRooms() const;
    int getRoomCount() const;

    Attendant* getAttendant();
    void setAttendant(Attendant* att);
};
