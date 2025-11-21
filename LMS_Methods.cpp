#include "LabManagementSystem.h"
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
    cout << "Successfully wrote " << count << " buildings to buildings.dat" << endl;
}

// Function to load buildings from binary file
void LabManagementSystem::loadBuildingsFromFile() {
    ifstream inFile("buildings.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open buildings.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_buildings.size() << " buildings from buildings.dat" << endl;
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
    cout << "Successfully wrote " << count << " academic officers to academic_officers.dat" << endl;
}

// Function to load academic officers from binary file
void LabManagementSystem::loadAcademicOfficersFromFile() {
    ifstream inFile("academic_officers.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open academic_officers.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_academicOfficers.size() << " academic officers from academic_officers.dat" << endl;
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
    cout << "Successfully wrote " << count << " attendants to attendants.dat" << endl;
}

// Function to load attendants from binary file
void LabManagementSystem::loadAttendantsFromFile() {
    ifstream inFile("attendants.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open attendants.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_attendants.size() << " attendants from attendants.dat" << endl;
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
    cout << "Successfully wrote " << count << " HOD to hods.dat" << endl;
}

// Function to load HODs from binary file
void LabManagementSystem::loadHODsFromFile() {
    ifstream inFile("hods.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open hods.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_hods.size() << " HOD(s) from hods.dat" << endl;
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
    cout << "Successfully wrote " << count << " TAs to tas.dat" << endl;
}

// Function to load TAs from binary file
void LabManagementSystem::loadTAsFromFile() {
    ifstream inFile("tas.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open tas.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_tas.size() << " TA(s) from tas.dat" << endl;
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
    cout << "Successfully wrote " << count << " Instructors to instructors.dat" << endl;
}

// Function to load Instructors from binary file
void LabManagementSystem::loadInstructorsFromFile() {
    ifstream inFile("instructors.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open instructors.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_instructors.size() << " Instructor(s) from instructors.dat" << endl;
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
    cout << "Successfully wrote " << count << " Rooms to rooms.dat" << endl;
}

// Function to load Rooms from binary file and assign to buildings
void LabManagementSystem::loadRoomsFromFile() {
    ifstream inFile("rooms.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open rooms.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << totalLoaded << " Room(s) from rooms.dat and assigned to buildings" << endl;
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
    cout << "Successfully wrote " << count << " Labs to labs.dat" << endl;
}

// Function to load Labs from binary file
void LabManagementSystem::loadLabsFromFile() {
    ifstream inFile("labs.dat", ios::binary);
    if (!inFile) {
        cerr << "Warning: Could not open labs.dat for reading. File may not exist yet." << endl;
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
    cout << "Successfully loaded " << m_labs.size() << " Lab(s) from labs.dat" << endl;
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
    cout << "Successfully wrote " << count << " lab sections to lab_sections.dat" << endl;
}

// Function to load LabSections from binary file and assign to Labs
void LabManagementSystem::loadLabSectionsFromFile() {
    ifstream inFile("lab_sections.dat", ios::binary);
    if (!inFile) {
        cout << "Warning: lab_sections.dat not found. No lab sections loaded." << endl;
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
            cout << "Warning: Lab " << data.labID << " not found for section " << data.sectionID << endl;
            // Still store in m_labSections for tracking
            m_labSections.push_back(move(section));
        }
    }

    inFile.close();
    
    // Count total sections across all labs
    int totalSections = 0;
    for (const auto& lab : m_labs) {
        totalSections += lab->getSectionCount();
    }
    cout << "Successfully loaded " << totalSections << " lab sections from lab_sections.dat" << endl;
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
    cout << "Successfully wrote " << count << " schedules to schedules.dat" << endl;
}

// Function to load Schedules from binary file and assign to LabSections
void LabManagementSystem::loadSchedulesFromFile() {
    ifstream inFile("schedules.dat", ios::binary);
    if (!inFile) {
        cout << "Warning: schedules.dat not found. No schedules loaded." << endl;
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
            parentSection->addSchedule(move(schedule));
        } else {
            cout << "Warning: LabSection " << data.labSectionID << " not found for schedule" << endl;
            // Still store in m_schedules for tracking
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
    cout << "Successfully loaded " << totalSchedules << " schedules from schedules.dat" << endl;
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
                
                const auto& schedules = section->getSchedules();
                for (const auto& schedule : schedules) {
                    cout << "    - Day: " << dayNames[schedule->getDayOfWeek()] 
                         << " (" << schedule->getDayOfWeek() << ")";
                    cout << " | Time: ";
                    schedule->getTiming().print();
                    cout << " | Makeup: " << (schedule->getIsMakeup() ? "Yes" : "No") << endl;
                }
            }
        }
    }
    cout << "-------------------------------------------\n" << endl;
}

// Minimal implementations so the program links. Full method bodies will be added later.
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
    cout << "LabManagementSystem initialized." << endl;

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
}

LabManagementSystem::~LabManagementSystem() {
    // cleanup if needed
}
