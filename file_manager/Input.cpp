#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Structs
struct Building {
    int buildingID;
    char name[100];
    int attendantID;
};

struct Room {
    int roomID;
    char roomNo[50];
    int capacity;
    int buildingID;
};

struct Officer {
    int officerID;
    char name[100];
    int managedBuildingID;
};

struct Attendant {
    int attendantID;
    char name[100];
    int buildingID;
};

int main() {
    ofstream outText("all_data.txt");
    if(!outText) {
        cout << "Error creating all_data.txt" << endl;
        return 1;
    }

    // --- Buildings ---
    ifstream inBuildings("../data/buildings.dat", ios::binary);
    if(inBuildings) {
        Building b[10];
        inBuildings.read((char*)b, sizeof(b));
        outText << "=== Buildings ===\n";
        for(int i=0;i<10;i++)
            outText << b[i].buildingID << ", " << b[i].name << ", " << b[i].attendantID << "\n";
        inBuildings.close();
    }

    // --- Rooms ---
    ifstream inRooms("../data/rooms.dat", ios::binary);
    if(inRooms) {
        Room r[50];
        inRooms.read((char*)r, sizeof(r));
        outText << "\n=== Rooms ===\n";
        for(int i=0;i<50;i++)
            outText << r[i].roomID << ", " << r[i].roomNo << ", " << r[i].capacity << ", " << r[i].buildingID << "\n";
        inRooms.close();
    }

    // --- Officers ---
    ifstream inOfficers("../data/officers.dat", ios::binary);
    if(inOfficers) {
        Officer o[10];
        inOfficers.read((char*)o, sizeof(o));
        outText << "\n=== Officers ===\n";
        for(int i=0;i<10;i++)
            outText << o[i].officerID << ", " << o[i].name << ", " << o[i].managedBuildingID << "\n";
        inOfficers.close();
    }

    // --- Attendants ---
    ifstream inAttendants("../data/attendants.dat", ios::binary);
    if(inAttendants) {
        Attendant a[10];
        inAttendants.read((char*)a, sizeof(a));
        outText << "\n=== Attendants ===\n";
        for(int i=0;i<10;i++)
            outText << a[i].attendantID << ", " << a[i].name << ", " << a[i].buildingID << "\n";
        inAttendants.close();
    }

    outText.close();
    cout << "All data written to all_data.txt successfully!" << endl;
    return 0;
}
