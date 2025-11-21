#pragma once

class Room {
private:
    int roomID;
    int capacity;
    char roomNumber[10];
    int buildingID;
public:
    Room(int ID, int cap, const char number[10], int bID);
    Room();
    ~Room();


};
