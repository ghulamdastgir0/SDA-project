#pragma once

class Room {
private:
    int roomID;
    int capacity;
    string roomNumber;
    int buildingID;
public:
    Room(int ID, int cap, const string& number, int bID);
    ~Room();


};
