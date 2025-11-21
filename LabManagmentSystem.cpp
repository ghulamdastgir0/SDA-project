#include "LabManagementSystem.h"

using namespace std;

int main()
{
    // STEP 1: UNCOMMENT THESE LINES ONLY ONCE TO WRITE THE BINARY FILES:
    // Then comment them back and run step 2
    
    // LabManagementSystem temp;
    // temp.writeBuildingsToFile();
    // temp.writeAcademicOfficersToFile();
    // temp.writeAttendantsToFile();
    // temp.writeHODsToFile();
    // temp.writeTAsToFile();
    // temp.writeInstructorsToFile();
    // temp.writeRoomsToFile();
    // temp.writeLabsToFile();
    // temp.writeLabSectionsToFile();
    // temp.writeSchedulesToFile();
    // return 0;
    

    // STEP 2: Run this after files are created
    LabManagementSystem LabSystem;
    LabSystem.printBuildings();
    LabSystem.printAcademicOfficers();
    LabSystem.printAttendants();
    LabSystem.printHODs();
    LabSystem.printTAs();
    LabSystem.printInstructors();
    LabSystem.printRooms();
    LabSystem.printLabs();
    LabSystem.printLabSections();
    LabSystem.printSchedules();
    LabSystem.run();

    return 0;
}