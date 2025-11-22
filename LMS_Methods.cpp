#include "LabManagementSystem.h"
#include "InstructorMenu.h"
#include "HODMenu.h"
#include "AttendantMenu.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Function to write initial building data to binary file
void LabManagementSystem::writeBuildingsToFile() {
    ofstream outFile("buildings.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open buildings.dat for writing." << endl;
        return;
    }

    // Building data: ID, Name, AttendantID
    struct BuildingData {
        int id;
        char name[100];
        int attendantID;
    };

    BuildingData buildings[] = {
        {101, "Computer Science Block", 5001},
        {102, "Electrical Engineering Wing", 5002},
        {103, "Mechanical Workshop", 5003},
        {104, "Civil Engineering Department", 5004},
        {105, "Physics Research Center", 5005},
        {106, "Chemistry Labs", 5006},
        {107, "Biology & Genetics", 5007},
        {108, "Mathematics Tower", 5008},
        {109, "Business School", 5009},
        {110, "Arts & Humanities", 5010}
    };

    int count = 10;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&buildings[i]), sizeof(BuildingData));
    }

    outFile.close();
    // suppressed: initial buildings write message
}

// Function to load buildings from binary file
void LabManagementSystem::loadBuildingsFromFile() {
    ifstream inFile("buildings.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct BuildingData {
        int id;
        char name[100];
        int attendantID;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in buildings.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        BuildingData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(BuildingData));
        
        if (!inFile) {
            cerr << "Error: Failed to read building data at index " << i << endl;
            break;
        }

        auto building = make_unique<Building>(data.id, string(data.name), data.attendantID);
        m_buildings.push_back(move(building));
    }

    inFile.close();
    // suppressed: buildings load message
}

// Function to print all buildings
void LabManagementSystem::printBuildings() const {
    cout << "\n=== Buildings List ===" << endl;
    cout << "Total Buildings: " << m_buildings.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& building : m_buildings) {
        cout << "ID: " << building->getID() 
             << " | Name: " << building->getName()
             << " | Attendant ID: " << building->getAttendantID() << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial academic officer data to binary file
void LabManagementSystem::writeAcademicOfficersToFile() {
    ofstream outFile("academic_officers.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open academic_officers.dat for writing." << endl;
        return;
    }

    // Academic Officer data: ID, Name, BuildingID
    struct AcademicOfficerData {
        int id;
        char name[100];
        int buildingID;
    };

    AcademicOfficerData officers[] = {
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

    int count = 10;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&officers[i]), sizeof(AcademicOfficerData));
    }

    outFile.close();
    // suppressed: academic officers write message
}

// Function to load academic officers from binary file
void LabManagementSystem::loadAcademicOfficersFromFile() {
    ifstream inFile("academic_officers.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct AcademicOfficerData {
        int id;
        char name[100];
        int buildingID;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in academic_officers.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        AcademicOfficerData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(AcademicOfficerData));
        
        if (!inFile) {
            cerr << "Error: Failed to read academic officer data at index " << i << endl;
            break;
        }

        auto officer = make_unique<AcademicOfficer>(data.id, string(data.name), data.buildingID);
        m_academicOfficers.push_back(move(officer));
    }

    inFile.close();
    // suppressed: academic officers load message
}

// Function to print all academic officers
void LabManagementSystem::printAcademicOfficers() const {
    cout << "\n=== Academic Officers List ===" << endl;
    cout << "Total Academic Officers: " << m_academicOfficers.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& officer : m_academicOfficers) {
        cout << "ID: " << officer->getId() 
             << " | Name: " << officer->getName()
             << " | Managed Building ID: " << officer->getManagedBuilding() << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial attendant data to binary file
void LabManagementSystem::writeAttendantsToFile() {
    ofstream outFile("attendants.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open attendants.dat for writing." << endl;
        return;
    }

    // Attendant data: ID, Name, BuildingID
    struct AttendantData {
        int id;
        char name[100];
        int buildingID;
    };

    AttendantData attendants[] = {
        {5001, "Alice Johnson", 101},
        {5002, "Bob Smith", 102},
        {5003, "Charlie Lee", 103},
        {5004, "Diana Ross", 104},
        {5005, "Edward Kim", 105},
        {5006, "Fiona Davis", 106},
        {5007, "George Brown", 107},
        {5008, "Hannah Wilson", 108},
        {5009, "Ian Clark", 109},
        {5010, "Julia Adams", 110}
    };

    int count = 10;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&attendants[i]), sizeof(AttendantData));
    }

    outFile.close();
    // suppressed: attendants write message
}

// Function to load attendants from binary file
void LabManagementSystem::loadAttendantsFromFile() {
    ifstream inFile("attendants.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct AttendantData {
        int id;
        char name[100];
        int buildingID;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in attendants.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        AttendantData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(AttendantData));
        
        if (!inFile) {
            cerr << "Error: Failed to read attendant data at index " << i << endl;
            break;
        }

        auto attendant = make_unique<Attendant>(string(data.name), data.buildingID, data.id);
        m_attendants.push_back(move(attendant));
    }

    inFile.close();
    // suppressed: attendants load message
}

// Function to print all attendants
void LabManagementSystem::printAttendants() const {
    cout << "\n=== Attendants List ===" << endl;
    cout << "Total Attendants: " << m_attendants.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& attendant : m_attendants) {
        cout << "ID: " << attendant->getId() 
             << " | Name: " << attendant->getName()
             << " | Building ID: " << attendant->getBuildingID() << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial HOD data to binary file
void LabManagementSystem::writeHODsToFile() {
    ofstream outFile("hods.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open hods.dat for writing." << endl;
        return;
    }

    // HOD data: ID, Name, Number of Lab IDs, then the Lab IDs
    struct HODData {
        int id;
        char name[100];
        int labCount;
        int labIds[50]; // Max 50 lab IDs
    };

    HODData hod;
    hod.id = 101;
    strcpy(hod.name, "Dr. SaifUllah");
    int assignedLabs[] = {201, 202, 203, 204, 205, 301, 302, 401, 402, 501, 502, 601, 602, 701, 702};
    hod.labCount = 15;
    for (int i = 0; i < hod.labCount; ++i) {
        hod.labIds[i] = assignedLabs[i];
    }

    int count = 1; // Only one HOD
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));
    outFile.write(reinterpret_cast<char*>(&hod), sizeof(HODData));

    outFile.close();
    // suppressed: HOD write message
}

// Function to load HODs from binary file
void LabManagementSystem::loadHODsFromFile() {
    ifstream inFile("hods.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct HODData {
        int id;
        char name[100];
        int labCount;
        int labIds[50];
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 100) {
        cerr << "Error: Invalid data in hods.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        HODData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(HODData));
        
        if (!inFile) {
            cerr << "Error: Failed to read HOD data at index " << i << endl;
            break;
        }

        // Convert lab IDs array to vector
        vector<int> labIds;
        for (int j = 0; j < data.labCount && j < 50; ++j) {
            labIds.push_back(data.labIds[j]);
        }

        auto hod = make_unique<HeadOfDepartment>(data.id, string(data.name), labIds);
        m_hods.push_back(move(hod));
    }

    inFile.close();
    // suppressed: HOD load message
}

// Function to print all HODs
void LabManagementSystem::printHODs() const {
    cout << "\n=== Head of Department List ===" << endl;
    cout << "Total HODs: " << m_hods.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& hod : m_hods) {
        cout << "ID: " << hod->getId() 
             << " | Name: " << hod->getName()
             << " | Managed Lab IDs: [";
        
        vector<int> labIds = hod->getManagedLabIds();
        for (size_t i = 0; i < labIds.size(); ++i) {
            cout << labIds[i];
            if (i < labIds.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial TA data to binary file
void LabManagementSystem::writeTAsToFile() {
    ofstream outFile("tas.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open tas.dat for writing." << endl;
        return;
    }

    // TA data: ID, Name, Number of Lab IDs, then the Lab IDs
    struct TAData {
        int id;
        char name[100];
        int labCount;
        int labIds[20]; // Max 20 lab IDs
    };

    TAData tas[] = {
        {4001, "Alex Martin", 2, {2001, 2002}},
        {4002, "Brian Lopez", 1, {2003}},
        {4003, "Chloe Kim", 1, {2004}},
        {4004, "David Green", 1, {2005}},
        {4005, "Ella Foster", 1, {2006}},
        {4006, "Frank Turner", 1, {2007}},
        {4007, "Grace Lee", 1, {2008}},
        {4008, "Harry Patel", 2, {2009, 2010}},
        {4009, "Rayan Ahmed", 2, {3001, 3002}},
        {4010, "Liam Hughes", 2, {4001, 4002}},
        {4011, "Dawood Shahzad", 3, {5001, 5002, 5003}},
        {4012, "Quinn Delgado", 1, {6001}},
        {4013, "Ruby Chen", 1, {6002}},
        {4014, "Steven Young", 1, {7001}},
        {4015, "Tara Mitchell", 1, {7002}}
    };

    int count = 15;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&tas[i]), sizeof(TAData));
    }

    outFile.close();
    // suppressed: TAs write message
}

// Function to load TAs from binary file
void LabManagementSystem::loadTAsFromFile() {
    ifstream inFile("tas.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct TAData {
        int id;
        char name[100];
        int labCount;
        int labIds[20];
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in tas.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        TAData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(TAData));
        
        if (!inFile) {
            cerr << "Error: Failed to read TA data at index " << i << endl;
            break;
        }

        // Convert lab IDs array to vector
        vector<int> labIds;
        for (int j = 0; j < data.labCount && j < 20; ++j) {
            labIds.push_back(data.labIds[j]);
        }

        auto ta = make_unique<TA>(data.id, string(data.name), labIds);
        m_tas.push_back(move(ta));
    }

    inFile.close();
    // suppressed: TAs load message
}

// Function to print all TAs
void LabManagementSystem::printTAs() const {
    cout << "\n=== Teaching Assistants List ===" << endl;
    cout << "Total TAs: " << m_tas.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& ta : m_tas) {
        cout << "ID: " << ta->getId() 
             << " | Name: " << ta->getName()
             << " | Assigned Lab IDs: [";
        
        const vector<int>& labIds = ta->getAssignedLabs();
        for (size_t i = 0; i < labIds.size(); ++i) {
            cout << labIds[i];
            if (i < labIds.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial Instructor data to binary file
void LabManagementSystem::writeInstructorsToFile() {
    ofstream outFile("instructors.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open instructors.dat for writing." << endl;
        return;
    }

    // Instructor data: ID, Name, Number of Lab IDs, then the Lab IDs
    struct InstructorData {
        int id;
        char name[100];
        int labCount;
        int labIds[20]; // Max 20 lab IDs
    };

    InstructorData instructors[] = {
        {3001, "Prof. Henry Walker", 1, {2001}},
        {3002, "Prof. Laura Bennett", 1, {2002}},
        {3003, "Prof. Michael Carter", 1, {2003}},
        {3004, "Prof. Susan Lee", 1, {2004}},
        {3005, "Prof. Daniel Brooks", 1, {2005}},
        {3006, "Prof. Olivia Chen", 1, {2006}},
        {3007, "Prof. Patrick Hughes", 1, {2007}},
        {3008, "Prof. Rachel Summers", 1, {2008}},
        {3009, "Prof. Victor Hale", 1, {2009}},
        {3010, "Prof. Sofia Turner", 1, {2010}},
        {3011, "Dr. Alan Murphy", 1, {3001}},
        {3012, "Dr. Jasmine Ford", 1, {3002}},
        {3013, "Dr. Ethan Russell", 1, {4001}},
        {3014, "Dr. Nadia Karim", 1, {4002}},
        {3015, "Engr. Thomas Reid", 2, {5001, 5002}},
        {3016, "Engr. Chloe Matthews", 2, {6001, 6002}},
        {3020, "Engr. Akhlaq Bhatti", 2, {7001, 7002}}
    };

    int count = 17;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&instructors[i]), sizeof(InstructorData));
    }

    outFile.close();
    // suppressed: instructors write message
}

// Function to load Instructors from binary file
void LabManagementSystem::loadInstructorsFromFile() {
    ifstream inFile("instructors.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct InstructorData {
        int id;
        char name[100];
        int labCount;
        int labIds[20];
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in instructors.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        InstructorData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(InstructorData));
        
        if (!inFile) {
            cerr << "Error: Failed to read Instructor data at index " << i << endl;
            break;
        }

        // Convert lab IDs array to vector
        vector<int> labIds;
        for (int j = 0; j < data.labCount && j < 20; ++j) {
            labIds.push_back(data.labIds[j]);
        }

        auto instructor = make_unique<Instructor>(data.id, string(data.name), labIds);
        m_instructors.push_back(move(instructor));
    }

    inFile.close();
    // suppressed: instructors load message
}

// Function to print all Instructors
void LabManagementSystem::printInstructors() const {
    cout << "\n=== Instructors List ===" << endl;
    cout << "Total Instructors: " << m_instructors.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& instructor : m_instructors) {
        cout << "ID: " << instructor->getId() 
             << " | Name: " << instructor->getName()
             << " | Assigned Lab IDs: [";
        
        vector<int> labIds = instructor->getAssignedLabIds();
        for (size_t i = 0; i < labIds.size(); ++i) {
            cout << labIds[i];
            if (i < labIds.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial Room data to binary file
void LabManagementSystem::writeRoomsToFile() {
    ofstream outFile("rooms.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open rooms.dat for writing." << endl;
        return;
    }

    // Room data: ID, roomNumber, capacity, buildingID
    struct RoomData {
        int id;
        char roomNumber[50];
        int capacity;
        int buildingID;
    };

    RoomData rooms[] = {
        {1, "CS-Lab-01", 40, 101}, {2, "CS-Lab-02", 40, 101}, {3, "CS-Server-Room", 15, 101},
        {4, "CS-Networking-Lab", 35, 101}, {5, "CS-Project-Room", 25, 101},
        {6, "EE-Circuits-Lab", 35, 102}, {7, "EE-Robotics-Lab", 30, 102}, {8, "EE-Controls-Lab", 40, 102},
        {9, "EE-Power-Lab", 25, 102}, {10, "EE-Embedded-Lab", 30, 102},
        {11, "ME-Machines-Shop", 50, 103}, {12, "ME-Thermo-Lab", 45, 103}, {13, "ME-Dynamics-Lab", 40, 103},
        {14, "ME-Workshop-A", 35, 103}, {15, "ME-Workshop-B", 35, 103},
        {16, "CE-Structures-Lab", 40, 104}, {17, "CE-Concrete-Lab", 35, 104}, {18, "CE-Soil-Testing-Lab", 35, 104},
        {19, "CE-Environmental-Lab", 30, 104}, {20, "CE-Hydraulics-Lab", 30, 104},
        {21, "PHY-Optics-Lab", 25, 105}, {22, "PHY-Quantum-Lab", 30, 105}, {23, "PHY-Laser-Lab", 20, 105},
        {24, "PHY-SolidState-Lab", 30, 105}, {25, "PHY-Research-Hall", 50, 105},
        {26, "CHM-Organic-Lab", 30, 106}, {27, "CHM-Inorganic-Lab", 30, 106}, {28, "CHM-Analytical-Lab", 35, 106},
        {29, "CHM-BioChem-Lab", 40, 106}, {30, "CHM-Research-Lab", 20, 106},
        {31, "BIO-Anatomy-Hall", 60, 107}, {32, "BIO-Genetics-Lab", 40, 107}, {33, "BIO-Microbiology-Lab", 35, 107},
        {34, "BIO-Botany-Lab", 30, 107}, {35, "BIO-Research-Lab", 25, 107},
        {36, "MATH-Seminar-Room", 100, 108}, {37, "MATH-Statistics-Lab", 40, 108}, {38, "MATH-Computer-Lab", 35, 108},
        {39, "MATH-Tutorial-Room-A", 30, 108}, {40, "MATH-Tutorial-Room-B", 30, 108},
        {41, "BIZ-CaseRoom-1", 50, 109}, {42, "BIZ-CaseRoom-2", 45, 109}, {43, "BIZ-Computer-Lab", 40, 109},
        {44, "BIZ-Research-Room", 30, 109}, {45, "BIZ-Presentation-Hall", 80, 109},
        {46, "ARTS-Studio-1", 40, 110}, {47, "ARTS-Studio-2", 35, 110}, {48, "ARTS-Media-Lab", 30, 110},
        {49, "ARTS-Design-Lab", 25, 110}, {50, "ARTS-Exhibition-Hall", 70, 110}
    };

    int count = 50;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&rooms[i]), sizeof(RoomData));
    }

    outFile.close();
    // suppressed: rooms write message
}

// Function to load Rooms from binary file and assign to buildings
void LabManagementSystem::loadRoomsFromFile() {
    ifstream inFile("rooms.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct RoomData {
        int id;
        char roomNumber[50];
        int capacity;
        int buildingID;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in rooms.dat" << endl;
        inFile.close();
        return;
    }

    int totalLoaded = 0;
    for (int i = 0; i < count; ++i) {
        RoomData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(RoomData));
        
        if (!inFile) {
            cerr << "Error: Failed to read Room data at index " << i << endl;
            break;
        }

        // Find the building and add the room to it
        for (auto& building : m_buildings) {
            if (building->getID() == data.buildingID) {
                auto room = make_unique<Room>(data.id, data.capacity, string(data.roomNumber), data.buildingID);
                building->addRoom(move(room));
                totalLoaded++;
                break;
            }
        }
    }

    inFile.close();
    // suppressed: rooms load message
}

// Function to print all Rooms organized by building
void LabManagementSystem::printRooms() const {
    cout << "\n=== Rooms List (by Building) ===" << endl;
    
    int totalRooms = 0;
    for (const auto& building : m_buildings) {
        const auto& rooms = building->getRooms();
        totalRooms += rooms.size();
        
        if (!rooms.empty()) {
            cout << "\n[Building: " << building->getName() << " (ID: " << building->getID() << ")]" << endl;
            cout << "  Rooms: " << rooms.size() << endl;
            cout << "  -------------------------------------------" << endl;
            
            for (const auto& room : rooms) {
                cout << "  ID: " << room->getID() 
                     << " | Room: " << room->getRoomNumber()
                     << " | Capacity: " << room->getCapacity() << endl;
            }
        }
    }
    
    cout << "\n=== Total Rooms: " << totalRooms << " ===\n" << endl;
}

// Function to write initial Lab data to binary file
void LabManagementSystem::writeLabsToFile() {
    ofstream outFile("labs.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cerr << "Error: Could not open labs.dat for writing." << endl;
        return;
    }

    // Lab data: ID, Code, Name
    struct LabData {
        int id;
        char code[50];
        char name[150];
    };

    LabData labs[] = {
        {201, "CS101-LAB", "Introduction to Programming Lab"},
        {202, "CS102-LAB", "Data Structures Lab"},
        {203, "CS103-LAB", "Object-Oriented Programming Lab"},
        {204, "CS104-LAB", "Database Systems Lab"},
        {205, "CS105-LAB", "Operating Systems Lab"},
        {301, "PHYS201-LAB", "General Physics I Lab"},
        {302, "PHYS202-LAB", "Modern Physics Lab"},
        {401, "CHEM201-LAB", "Organic Chemistry Lab"},
        {402, "CHEM202-LAB", "Physical Chemistry Lab"},
        {501, "EE201-LAB", "Circuits and Instrumentation Lab"},
        {502, "EE202-LAB", "Digital Logic Design Lab"},
        {601, "ME201-LAB", "Mechanics of Materials Lab"},
        {602, "ME202-LAB", "Thermodynamics Lab"},
        {701, "CE201-LAB", "Structural Analysis Lab"},
        {702, "CE202-LAB", "Surveying and Geomatics Lab"}
    };

    int count = 15;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&labs[i]), sizeof(LabData));
    }

    outFile.close();
    // suppressed: labs write message
}

// Function to load Labs from binary file
void LabManagementSystem::loadLabsFromFile() {
    ifstream inFile("labs.dat", ios::binary);
    if (!inFile) {
        return;
    }

    struct LabData {
        int id;
        char code[50];
        char name[150];
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cerr << "Error: Invalid data in labs.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        LabData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(LabData));
        
        if (!inFile) {
            cerr << "Error: Failed to read Lab data at index " << i << endl;
            break;
        }

        auto lab = make_unique<Lab>(data.id, string(data.code), string(data.name));
        m_labs.push_back(move(lab));
    }

    inFile.close();
    // suppressed: labs load message
}

// Function to print all Labs
void LabManagementSystem::printLabs() const {
    cout << "\n=== Labs List ===" << endl;
    cout << "Total Labs: " << m_labs.size() << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& lab : m_labs) {
        cout << "ID: " << lab->getID() 
             << " | Code: " << lab->getCode()
             << " | Name: " << lab->getName() << endl;
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial LabSection data to binary file
void LabManagementSystem::writeLabSectionsToFile() {
    ofstream outFile("lab_sections.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cout << "Error: Could not create lab_sections.dat" << endl;
        return;
    }

    // LabSection data: SectionID, LabID, CourseCode, InstructorID, TAID, RoomNo
    struct LabSectionData {
        int sectionID;
        int labID;
        char courseCode[50];
        int instructorID;
        int taID;
        int roomNo;
    };

    LabSectionData sections[] = {
        {2001, 201, "CS101", 3001, 4001, 1},
        {2002, 201, "CS101", 3002, 4002, 2},
        {2003, 202, "CS102", 3003, 4003, 3},
        {2004, 202, "CS102", 3004, 4004, 4},
        {2005, 203, "CS103", 3005, 4005, 5},
        {2006, 203, "CS103", 3006, 4006, 1},
        {2007, 204, "CS104", 3007, 4007, 2},
        {2008, 204, "CS104", 3008, 4008, 3},
        {2009, 205, "CS105", 3009, 4009, 4},
        {2010, 205, "CS105", 3010, 4010, 5},
        {3001, 301, "PHYS201", 3011, 4011, 21},
        {3002, 302, "PHYS202", 3012, 4012, 22},
        {4001, 401, "CHEM201", 3013, 4013, 26},
        {4002, 402, "CHEM202", 3014, 4014, 27},
        {5001, 501, "EE201", 3015, 4015, 6},
        {5002, 501, "EE201", 3016, 4016, 7},
        {5003, 502, "EE202", 3017, 4017, 8},
        {6001, 601, "ME201", 3018, 4018, 11},
        {6002, 602, "ME202", 3019, 4019, 12},
        {7001, 701, "CE201", 3020, 4020, 16},
        {7002, 702, "CE202", 3021, 4021, 17}
    };

    int count = 21;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&sections[i]), sizeof(LabSectionData));
    }

    outFile.close();
    // suppressed: lab sections write message
}

// Function to load LabSections from binary file and assign to Labs
void LabManagementSystem::loadLabSectionsFromFile() {
    ifstream inFile("lab_sections.dat", ios::binary);
    if (!inFile) {
        // suppressed: lab_sections.dat missing
        return;
    }

    struct LabSectionData {
        int sectionID;
        int labID;
        char courseCode[50];
        int instructorID;
        int taID;
        int roomNo;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cout << "Error: Invalid count in lab_sections.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        LabSectionData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(LabSectionData));
        
        if (!inFile) {
            cout << "Error: Failed to read lab section " << i+1 << endl;
            break;
        }

        // Create LabSection object
        auto section = make_unique<LabSection>(
            data.sectionID,
            data.labID,
            string(data.courseCode),
            data.instructorID,
            data.taID,
            data.roomNo
        );

        // Find the parent Lab and add this section to it
        Lab* parentLab = nullptr;
        for (auto& lab : m_labs) {
            if (lab->getID() == data.labID) {
                parentLab = lab.get();
                break;
            }
        }

        if (parentLab) {
            parentLab->addSection(move(section));
        } else {
            // suppressed: lab not found for section (kept in m_labSections)
            m_labSections.push_back(move(section));
        }
    }

    inFile.close();
    
    // Count total sections across all labs
    int totalSections = 0;
    for (const auto& lab : m_labs) {
        totalSections += lab->getSectionCount();
    }
    // suppressed: lab sections load message
}

// Function to print all LabSections organized by Lab
void LabManagementSystem::printLabSections() const {
    cout << "\n=== Lab Sections List (Organized by Lab) ===" << endl;
    
    int totalSections = 0;
    for (const auto& lab : m_labs) {
        totalSections += lab->getSectionCount();
    }
    
    cout << "Total Lab Sections: " << totalSections << endl;
    cout << "-------------------------------------------" << endl;
    
    for (const auto& lab : m_labs) {
        if (lab->getSectionCount() > 0) {
            cout << "\nLab: " << lab->getName() << " (ID=" << lab->getID() << ", Code=" << lab->getCode() << ")" << endl;
            cout << "  Sections: " << lab->getSectionCount() << endl;
            
            const auto& sections = lab->getSections();
            for (const auto& section : sections) {
                cout << "    - Section " << section->getSectionID() 
                     << " | Course: " << section->getCourseCode()
                     << " | Instructor: " << section->getInstructorID()
                     << " | TA: " << section->getTAID()
                     << " | Room: " << section->getRoomNo() << endl;
            }
        }
    }
    cout << "-------------------------------------------\n" << endl;
}

// Function to write initial Schedule data to binary file
void LabManagementSystem::writeSchedulesToFile() {
    ofstream outFile("schedules.dat", ios::binary | ios::trunc);
    if (!outFile) {
        cout << "Error: Could not create schedules.dat" << endl;
        return;
    }

    // Schedule data: LabSectionID, DayOfWeek, StartHr, EndHr, StartMin, EndMin
    struct ScheduleData {
        int labSectionID;
        int dayOfWeek;
        int startHr;
        int endHr;
        int startMin;
        int endMin;
    };

    ScheduleData schedules[] = {
        {2001, 1, 9, 11, 0, 0},
        {2002, 1, 11, 13, 0, 0},
        {2003, 1, 13, 15, 0, 0},
        {2004, 1, 15, 17, 0, 0},
        {2005, 1, 17, 19, 0, 0},
        {2006, 1, 19, 21, 0, 0},
        {2007, 1, 8, 10, 0, 0},
        {2008, 1, 10, 12, 0, 0},
        {2009, 1, 12, 14, 0, 0},
        {2010, 1, 14, 16, 0, 0},
        {3001, 2, 9, 11, 0, 0},
        {3002, 2, 11, 13, 0, 0},
        {4001, 3, 9, 11, 0, 0},
        {4002, 3, 11, 13, 0, 0},
        {5001, 4, 9, 11, 0, 0},
        {5002, 4, 11, 13, 0, 0},
        {5003, 4, 13, 15, 0, 0},
        {6001, 5, 9, 11, 0, 0},
        {6002, 5, 11, 13, 0, 0},
        {7001, 6, 9, 11, 0, 0},
        {7002, 6, 11, 13, 0, 0}
    };

    int count = 21;
    outFile.write(reinterpret_cast<char*>(&count), sizeof(int));

    for (int i = 0; i < count; ++i) {
        outFile.write(reinterpret_cast<char*>(&schedules[i]), sizeof(ScheduleData));
    }

    outFile.close();
    // suppressed: schedules write message
}

// Function to load Schedules from binary file and assign to LabSections
void LabManagementSystem::loadSchedulesFromFile() {
    ifstream inFile("schedules.dat", ios::binary);
    if (!inFile) {
        // suppressed: schedules.dat missing
        return;
    }

    struct ScheduleData {
        int labSectionID;
        int dayOfWeek;
        int startHr;
        int endHr;
        int startMin;
        int endMin;
    };

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    
    if (!inFile || count < 0 || count > 1000) {
        cout << "Error: Invalid count in schedules.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        ScheduleData data;
        inFile.read(reinterpret_cast<char*>(&data), sizeof(ScheduleData));
        
        if (!inFile) {
            cout << "Error: Failed to read schedule " << i+1 << endl;
            break;
        }

        // Create Schedule object
        auto schedule = make_unique<Schedule>(
            data.labSectionID,
            data.dayOfWeek,
            data.startHr,
            data.endHr,
            data.startMin,
            data.endMin
        );

        // Find the parent LabSection and add this schedule to it
        LabSection* parentSection = nullptr;
        for (auto& lab : m_labs) {
            const auto& sections = lab->getSections();
            for (const auto& section : sections) {
                if (section->getSectionID() == data.labSectionID) {
                    parentSection = section.get();
                    break;
                }
            }
            if (parentSection) break;
        }

        if (parentSection) {
            parentSection->setSchedule(move(schedule));
        } else {
            // suppressed: lab section not found for schedule (kept in m_schedules)
            m_schedules.push_back(move(schedule));
        }
    }

    inFile.close();
    
    // Count total schedules across all lab sections
    int totalSchedules = 0;
    for (const auto& lab : m_labs) {
        const auto& sections = lab->getSections();
        for (const auto& section : sections) {
            totalSchedules += section->getScheduleCount();
        }
    }
    // suppressed: schedules load message
}

// Function to print all Schedules organized by LabSection
void LabManagementSystem::printSchedules() const {
    cout << "\n=== Schedules List (Organized by Lab Section) ===" << endl;
    
    int totalSchedules = 0;
    for (const auto& lab : m_labs) {
        const auto& sections = lab->getSections();
        for (const auto& section : sections) {
            totalSchedules += section->getScheduleCount();
        }
    }
    
    cout << "Total Schedules: " << totalSchedules << endl;
    cout << "-------------------------------------------" << endl;
    
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    for (const auto& lab : m_labs) {
        const auto& sections = lab->getSections();
        for (const auto& section : sections) {
            if (section->getScheduleCount() > 0) {
                cout << "\nLabSection " << section->getSectionID() 
                     << " (Course: " << section->getCourseCode() << ")" << endl;
                cout << "  Schedules: " << section->getScheduleCount() << endl;
                
                const Schedule* schedule = section->getSchedule();
                if (schedule) {
                    cout << "    - Day: " << dayNames[schedule->getDayOfWeek()] 
                         << " (" << schedule->getDayOfWeek() << ")";
                    cout << " | Time: ";
                    schedule->getTiming().print();
                    cout << endl;
                }
            }
        }
    }
    cout << "-------------------------------------------\n" << endl;
}

// Minimal implementations so the program links. Full method bodies will be added later.
// Submit an instructor request: create request object, store in memory and persist to pendingRequest.dat
InstructorRequest* LabManagementSystem::submitInstructorRequest(int instructorId, int labId, int weekNumber, const string &reason) {
    auto req = make_unique<InstructorRequest>(labId, instructorId, weekNumber, reason);
    InstructorRequest* ptr = req.get();

    // store in memory
    m_requests.push_back(move(req));

    // persist all pending requests to file (overwrite) so the file always reflects current state
    ofstream pout("pendingRequest.dat", ios::binary | ios::trunc);
    if (pout) {
        int count = (int)m_requests.size();
        pout.write(reinterpret_cast<char*>(&count), sizeof(int));
        for (const auto &rqptr : m_requests) {
            if (!rqptr) continue;
            int labID = rqptr->getLabId();
            int instID = rqptr->getInstructorId();
            int weekNo = rqptr->getWeekNumber();
            int status = rqptr->getIsApproved() ? 1 : (rqptr->getIsDenied() ? 2 : 0);
            pout.write(reinterpret_cast<char*>(&labID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&instID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&weekNo), sizeof(int));
            pout.write(reinterpret_cast<char*>(&status), sizeof(int));
            int len = (int)rqptr->getReason().size();
            pout.write(reinterpret_cast<char*>(&len), sizeof(int));
            if (len > 0) pout.write(rqptr->getReason().data(), len);
        }
        pout.close();
    }

    // return pointer to the stored request (owned by m_requests)
    return ptr;
}


LabManagementSystem::LabManagementSystem() 
    : m_academicOfficers(),
      m_attendants(),
      m_instructors(),
      m_tas(),
      m_hods(),
      m_buildings(),
      m_labs(),
      m_labSections(),
      m_schedules(),
      m_timeSheets(),
      m_requests()
{
    // All member vectors are initialized as empty via member initializer list.
    // The unique_ptr containers will manage memory automatically.
    // suppressed: initialization message

    loadBuildingsFromFile();
    loadAcademicOfficersFromFile();
    loadAttendantsFromFile();
    loadHODsFromFile();
    loadTAsFromFile();
    loadInstructorsFromFile();

    loadRoomsFromFile();  // Load rooms after buildings
    loadLabsFromFile();
    loadLabSectionsFromFile();  // Load lab sections after labs
    loadSchedulesFromFile();  // Load schedules after lab sections
    loadPendingRequestsFromFile();  // Load pending instructor requests
    // Load persisted time sheets (if any)
    loadTimeSheetsFromFile();
}

void LabManagementSystem::loadTimeSheetsFromFile() {
    ifstream inFile("timeSheets.dat", ios::binary);
    if (!inFile) {
        // suppressed: timeSheets.dat missing
        return;
    }

    int count = 0;
    inFile.read(reinterpret_cast<char*>(&count), sizeof(int));
    if (!inFile || count < 0 || count > 100000) {
        cout << "Error: Invalid data in timeSheets.dat" << endl;
        inFile.close();
        return;
    }

    for (int i = 0; i < count; ++i) {
        int labID = 0;
        int weekNo = 0;
        int dayOfWeek = 0;
        int startHr = 0, endHr = 0, startMin = 0, endMin = 0;
        inFile.read(reinterpret_cast<char*>(&labID), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&weekNo), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&dayOfWeek), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&startHr), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&endHr), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&startMin), sizeof(int));
        inFile.read(reinterpret_cast<char*>(&endMin), sizeof(int));
        if (!inFile) break;
        auto ts = make_unique<TimeSheet>(labID, dayOfWeek, weekNo, startHr, endHr, startMin, endMin);
        m_timeSheets.push_back(move(ts));
    }

    inFile.close();
    // suppressed: timesheets load message
}

// helper to persist timesheets
void writeTimeSheetsToFileHelper(const vector<unique_ptr<TimeSheet>> &timeSheets) {
    ofstream out("timeSheets.dat", ios::binary | ios::trunc);
    if (!out) return;
    int count = (int)timeSheets.size();
    out.write(reinterpret_cast<char*>(&count), sizeof(int));
    for (const auto &ts : timeSheets) {
        if (!ts) continue;
        int labID = ts->getLabID();
        int weekNo = ts->getWeekNumber();
        int dayOfWeek = ts->getDayOfWeek();
        int startHr = ts->getTiming().getStartHour();
        int endHr = ts->getTiming().getEndHour();
        int startMin = ts->getTiming().getStartMin();
        int endMin = ts->getTiming().getEndMin();
        out.write(reinterpret_cast<char*>(&labID), sizeof(int));
        out.write(reinterpret_cast<char*>(&weekNo), sizeof(int));
        out.write(reinterpret_cast<char*>(&dayOfWeek), sizeof(int));
        out.write(reinterpret_cast<char*>(&startHr), sizeof(int));
        out.write(reinterpret_cast<char*>(&endHr), sizeof(int));
        out.write(reinterpret_cast<char*>(&startMin), sizeof(int));
        out.write(reinterpret_cast<char*>(&endMin), sizeof(int));
    }
    out.close();
}

void LabManagementSystem::loadPendingRequestsFromFile() {
    ifstream pin("pendingRequest.dat", ios::binary);
    if (pin) {
        int count = 0;
        pin.read(reinterpret_cast<char*>(&count), sizeof(int));
        if (pin && count > 0 && count < 100000) {
            for (int i = 0; i < count; ++i) {
                int labID = 0;
                int instID = 0;
                int weekNo = 0;
                int statusInt = 0; // 0 = pending, 1 = approved, 2 = denied
                pin.read(reinterpret_cast<char*>(&labID), sizeof(int));
                pin.read(reinterpret_cast<char*>(&instID), sizeof(int));
                pin.read(reinterpret_cast<char*>(&weekNo), sizeof(int));
                pin.read(reinterpret_cast<char*>(&statusInt), sizeof(int));
                int reasonLen = 0;
                pin.read(reinterpret_cast<char*>(&reasonLen), sizeof(int));
                string reason;
                if (reasonLen > 0 && reasonLen < 10000) {
                    reason.resize(reasonLen);
                    pin.read(&reason[0], reasonLen);
                }
                if (!pin) break;
                auto req = make_unique<InstructorRequest>(labID, instID, weekNo, reason);
                if (statusInt == 1) req->ApproveRequest();
                else if (statusInt == 2) req->DenyRequest();
                InstructorRequest* reqPtr = req.get();
                m_requests.push_back(move(req));
                
                // Link loaded request back to its instructor
                Instructor* instr = findInstructorById(instID);
                if (instr) {
                    instr->getRequests().push_back(reqPtr);
                }
            }
        }
        pin.close();
        // suppressed: pending requests loaded message
    }
}

LabManagementSystem::~LabManagementSystem() {
    // On shutdown persist pending requests to disk (overwrite pendingRequest.dat)
    ofstream pout("pendingRequest.dat", ios::binary | ios::trunc);
    if (pout) {
        int count = (int)m_requests.size();
        pout.write(reinterpret_cast<char*>(&count), sizeof(int));
        for (const auto &rqptr : m_requests) {
            if (!rqptr) continue;
            int labID = rqptr->getLabId();
            int instID = rqptr->getInstructorId();
            int weekNo = rqptr->getWeekNumber();
            int status = rqptr->getIsApproved() ? 1 : (rqptr->getIsDenied() ? 2 : 0);
            pout.write(reinterpret_cast<char*>(&labID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&instID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&weekNo), sizeof(int));
            pout.write(reinterpret_cast<char*>(&status), sizeof(int));
            int len = (int)rqptr->getReason().size();
            pout.write(reinterpret_cast<char*>(&len), sizeof(int));
            if (len > 0) pout.write(rqptr->getReason().data(), len);
        }
        pout.close();
        // suppressed: pending requests saved message
    }

    // persist time sheets as well
    writeTimeSheetsToFileHelper(m_timeSheets);
}

bool LabManagementSystem::processRequest(int requestId, bool approve) {
    int idx = requestId - 1; // requestId is 1-based in menus
    if (idx < 0 || idx >= (int)m_requests.size()) return false;
    auto &req = m_requests[idx];
    if (!req) return false;

    if (approve) {
        req->setApproved(true);
        // append to approvedRequest.dat
        ofstream aout("approvedRequest.dat", ios::binary | ios::app);
        if (aout) {
            int labID = req->getLabId();
            int instID = req->getInstructorId();
            int weekNo = req->getWeekNumber();
            int status = 1; // approved
            aout.write(reinterpret_cast<char*>(&labID), sizeof(int));
            aout.write(reinterpret_cast<char*>(&instID), sizeof(int));
            aout.write(reinterpret_cast<char*>(&weekNo), sizeof(int));
            aout.write(reinterpret_cast<char*>(&status), sizeof(int));
            int len = (int)req->getReason().size();
            aout.write(reinterpret_cast<char*>(&len), sizeof(int));
            if (len > 0) aout.write(req->getReason().data(), len);
            aout.close();
        }
    } else {
        req->setDenied(true);
    }

    // persist all pending requests (overwrite pendingRequest.dat)
    ofstream pout("pendingRequest.dat", ios::binary | ios::trunc);
    if (pout) {
        int count = (int)m_requests.size();
        pout.write(reinterpret_cast<char*>(&count), sizeof(int));
        for (const auto &rqptr : m_requests) {
            if (!rqptr) continue;
            int labID = rqptr->getLabId();
            int instID = rqptr->getInstructorId();
            int weekNo = rqptr->getWeekNumber();
            int status = rqptr->getIsApproved() ? 1 : (rqptr->getIsDenied() ? 2 : 0);
            pout.write(reinterpret_cast<char*>(&labID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&instID), sizeof(int));
            pout.write(reinterpret_cast<char*>(&weekNo), sizeof(int));
            pout.write(reinterpret_cast<char*>(&status), sizeof(int));
            int len = (int)rqptr->getReason().size();
            pout.write(reinterpret_cast<char*>(&len), sizeof(int));
            if (len > 0) pout.write(rqptr->getReason().data(), len);
        }
        pout.close();
    }

    return true;
}

TimeSheet* LabManagementSystem::recordTimeSheet(int labId, int dayOfWeek, int weekNo, const Timing &time) {
    auto ts = make_unique<TimeSheet>(labId, dayOfWeek, weekNo, time.getStartHour(), time.getEndHour(), time.getStartMin(), time.getEndMin());
    TimeSheet* ptr = ts.get();
    m_timeSheets.push_back(move(ts));
    return ptr;
}

Instructor* LabManagementSystem::findInstructorById(int id) const {
    for (const auto &instr : m_instructors) {
        if (instr && instr->getId() == id) {
            return instr.get();
        }
    }
    return nullptr;
}

Attendant* LabManagementSystem::findAttendantById(int id) const {
    for (const auto &att : m_attendants) {
        if (att && att->getId() == id) return att.get();
    }
    return nullptr;
}

std::vector<InstructorRequest*> LabManagementSystem::getPendingRequests() const {
    std::vector<InstructorRequest*> out;
    out.reserve(m_requests.size());
    for (const auto &u : m_requests) {
        if (u) out.push_back(u.get());
    }
    return out;
}

vector<Schedule> LabManagementSystem::getWeeklySchedule(int weekNumber) const {
    // Return all schedules across all lab sections (weekNumber currently unused)
    vector<Schedule> out;
    for (const auto &lab : m_labs) {
        const auto &sections = lab->getSections();
        for (const auto &section : sections) {
            const Schedule* s = section->getSchedule();
            if (s) out.push_back(*s);
        }
    }
    return out;
}

vector<TimeSheet> LabManagementSystem::getFilledTimeSheetsForWeek(int weekNumber) const {
    vector<TimeSheet> out;
    for (const auto &ts : m_timeSheets) {
        if (!ts) continue;
        if (ts->getWeekNumber() == weekNumber) out.push_back(*ts);
    }
    return out;
}

vector<TimeSheet> LabManagementSystem::getTimeSheetsForLab(int labId) const {
    vector<TimeSheet> out;
    for (const auto &ts : m_timeSheets) {
        if (!ts) continue;
        if (ts->getLabID() == labId) out.push_back(*ts);
    }
    return out;
}

double LabManagementSystem::computeTotalContactHoursForLab(int labId) const {
    double totalMinutes = 0.0;
    for (const auto &lab : m_labs) {
        if (lab->getID() == labId) {
            const auto &sections = lab->getSections();
            for (const auto &sec : sections) {
                const Schedule* s = sec->getSchedule();
                if (s) {
                    // assume Timing has getStartHr/getStartMin/getEndHr/getEndMin
                    const Timing &t = s->getTiming();
                    int start = t.getStartHour()*60 + t.getStartMin();
                    int end = t.getEndHour()*60 + t.getEndMin();
                    totalMinutes += (end - start);
                }
            }
            break;
        }
    }
    return totalMinutes/60.0; // hours
}

int LabManagementSystem::computeLeavesForLab(int labId) const {
    int leaves = 0;
    for (const auto &lab : m_labs) {
        if (lab->getID() == labId) {
            const auto &sections = lab->getSections();
            for (const auto &sec : sections) {
                // LabSection does not expose leaves getter; assume 0 for now
            }
            break;
        }
    }
    return leaves;
}

void LabManagementSystem::run() {
    cout << "Lab Management System (interactive)." << endl;
    // suppressed: loaded requests message

    // Ask for instructor ID
    cout << "Login as (1) Instructor, (2) HOD or (3) Attendant: ";
    int role = 0; if (!(cin >> role)) { cin.clear(); cin.ignore(10000,'\n'); return; }
    cin.ignore();
    if (role == 1) {
        int instructorId = 0;
        Instructor* instructor = nullptr;
        while (!instructor) {
            cout << "Enter Instructor ID: ";
            cin >> instructorId;
            cin.ignore(); // Clear newline from input buffer
            instructor = findInstructorById(instructorId);
            if (!instructor) {
                cout << "ERROR: Instructor with ID " << instructorId << " not found. Please try again.\n" << endl;
            }
        }
        InstructorMenu menu(this, instructor);
        menu.displayMenu();
    } else if (role == 2) {
        int hodId = 0;
        HeadOfDepartment* hod = nullptr;
        while (!hod) {
            cout << "Enter HOD ID: ";
            cin >> hodId;
            cin.ignore();
            for (const auto &h : m_hods) if (h && h->getId() == hodId) { hod = h.get(); break; }
            if (!hod) cout << "ERROR: HOD with ID " << hodId << " not found. Please try again.\n" << endl;
        }
        // show HOD menu
        HODMenu hmenu(this, hod);
        hmenu.displayMenu();
    } else if (role == 3) {
        int attId = 0;
        Attendant* att = nullptr;
        while (!att) {
            cout << "Enter Attendant ID: ";
            cin >> attId;
            cin.ignore();
            att = findAttendantById(attId);
            if (!att) cout << "ERROR: Attendant with ID " << attId << " not found. Please try again.\n" << endl;
        }
        AttendantMenu amenu(this, att);
        amenu.displayMenu();
    } else {
        cout << "Invalid role selection. Exiting." << endl;
    }
}

