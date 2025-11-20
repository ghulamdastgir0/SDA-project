#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// Struct definition for Officer
struct Officer {
    int officerID;
    char name[100];
    int managedBuildingID;
};

int main() {
    // Array of 10 officers
    Officer officers[10] = {
        {901, "Dr. Sarah Connor", 101},
        {902, "Mr. John Smith", 102},
        {903, "Ms. Emily Davis", 103},
        {904, "Dr. Alan Grant", 104},
        {905, "Mr. Bruce Wayne", 105},
        {906, "Ms. Diana Prince", 106},
        {907, "Mr. Clark Kent", 107},
        {908, "Dr. Emmett Brown", 108},
        {909, "Ms. Ellen Ripley", 109},
        {910, "Mr. Tony Stark", 110}
    };

    // --- Writing officers to binary file ---
    ofstream outFile("officers.dat", ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    outFile.write((char*)officers, sizeof(officers));
    outFile.close();
    cout << "All officer records saved successfully in officers.dat" << endl;

    // --- Reading officers from binary file ---
    ifstream inFile("officers.dat", ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    Officer readOfficers[10];
    inFile.read((char*)readOfficers, sizeof(readOfficers));
    inFile.close();

    // Display officers to verify
    cout << "\nReading from binary file:\n";
    for (int i = 0; i < 10; i++) {
        cout << "OfficerID: " << readOfficers[i].officerID
             << ", Name: " << readOfficers[i].name
             << ", ManagedBuildingID: " << readOfficers[i].managedBuildingID << endl;
    }

    return 0;
}