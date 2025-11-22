#include "InstructorMenu.h"
#include "Lab.h"
#include "LabSection.h"
#include "Schedule.h"
#include <vector>
#include <iostream>

using namespace std;

void InstructorMenu::displayMenu() {
    int choice = 0;
    
    while (choice != 5) {
        cout << "\n========================================" << endl;
        cout << "      Instructor Menu" << endl;
        cout << "      Welcome, " << instructor->getName() << "!" << endl;
        cout << "========================================" << endl;
        cout << "1. View My Lab Schedules" << endl;
        cout << "2. View Timesheets" << endl;
        cout << "3. Add New Request" << endl;
        cout << "4. View My Requests" << endl;
        cout << "5. Exit" << endl;
        cout << "========================================" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;
        cin.ignore();
        
        cout << endl;
        
        switch (choice) {
            case 1:
                viewLabSchedules();
                break;
            case 2:
                viewTimesheets();
                break;
            case 3:
                addRequest();
                break;
            case 4:
                viewMyRequests();
                break;
            case 5:
                cout << "Exiting Instructor Menu. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}

void InstructorMenu::viewLabSchedules() {
    cout << "========================================" << endl;
    cout << "      My Lab Schedules" << endl;
    cout << "========================================\n" << endl;
    
    int instructorId = instructor->getId();
    bool foundSchedules = false;
    
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    // Access labs through LMS (we need to add a getter for m_labs)
    // For now, iterate through instructor's assigned sections
    vector<int> assignedLabIds = instructor->getAssignedLabIds();
    
    cout << "Lab sections you are teaching:\n" << endl;
    
    // Note: This requires access to LMS's lab data
    // We'll need to add a helper method in LabManagementSystem to get this info
    cout << "Instructor ID: " << instructorId << endl;
    cout << "Assigned Lab IDs: ";
    for (size_t i = 0; i < assignedLabIds.size(); ++i) {
        cout << assignedLabIds[i];
        if (i < assignedLabIds.size() - 1) cout << ", ";
    }
    cout << "\n" << endl;
    
    cout << "NOTE: Full schedule display requires additional LMS integration." << endl;
    cout << "Contact system administrator for detailed schedule information." << endl;
}

void InstructorMenu::viewTimesheets() {
    cout << "========================================" << endl;
    cout << "      My Timesheets" << endl;
    cout << "========================================\n" << endl;
    
    cout << "Timesheet functionality is not yet implemented." << endl;
    cout << "This feature will be available in a future update." << endl;
    cout << "\nExpected features:" << endl;
    cout << "  - View filled timesheets for your labs" << endl;
    cout << "  - Track contact hours" << endl;
    cout << "  - Monitor attendance records" << endl;
}

void InstructorMenu::addRequest() {
    cout << "========================================" << endl;
    cout << "      Add New Request" << endl;
    cout << "========================================\n" << endl;
    
    int instructorId = instructor->getId();
    
    // Display assigned lab sections (we need LMS access to get full lab info)
    cout << "Your Lab Sections:" << endl;
    vector<int> assignedLabIds = instructor->getAssignedLabIds();

    if (assignedLabIds.empty()) {
        cout << "You have no assigned lab sections." << endl;
        return;
    }

    cout << "Assigned Lab Section IDs: ";
    for (size_t i = 0; i < assignedLabIds.size(); ++i) {
        cout << assignedLabIds[i];
        if (i < assignedLabIds.size() - 1) cout << ", ";
    }
    cout << "\n";

    cout << "Enter Lab Section ID (from your assigned labs): ";
    int labId = 0;
    cin >> labId;
    cin.ignore();
    
    // Validate that instructor has this lab
    bool hasLab = false;
    for (int id : assignedLabIds) {
        if (id == labId) {
            hasLab = true;
            break;
        }
    }
    
    if (!hasLab) {
        cout << "ERROR: Lab Section ID " << labId << " is not assigned to you." << endl;
        return;
    }
    
    cout << "Enter Week number for the makeup (e.g., 10): ";
    int weekNumber = 0; cin >> weekNumber; cin.ignore();
    if (weekNumber < 1) { cout << "ERROR: Invalid week number." << endl; return; }

    cout << "Enter Day Number (1=Monday, 2=Tuesday, ..., 7=Sunday): ";
    int dayNumber = 0; cin >> dayNumber; cin.ignore();
    if (dayNumber < 1 || dayNumber > 7) { cout << "ERROR: Invalid day number. Please use 1-7." << endl; return; }

    cout << "Enter Start hour (0-23): "; int sHr=0; cin >> sHr; cin.ignore();
    cout << "Enter Start minute (0-59): "; int sMin=0; cin >> sMin; cin.ignore();
    cout << "Enter End hour (0-23): "; int eHr=0; cin >> eHr; cin.ignore();
    cout << "Enter End minute (0-59): "; int eMin=0; cin >> eMin; cin.ignore();

    cout << "Enter Reason for Request: ";
    string reason; getline(cin, reason);

    // Submit through instructor's method with week/day and times
    int requestCount = instructor->createMakeupRequest(*lms, labId, weekNumber, dayNumber, sHr, sMin, eHr, eMin, reason);
    
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    cout << "\n========== Request Submitted ===========" << endl;
    cout << "Lab ID: " << labId << endl;
    cout << "Week: " << weekNumber << " | Day: " << dayNames[dayNumber] << " (" << dayNumber << ")" << endl;
    cout << "Reason: " << reason << endl;
    cout << "Status: Pending Approval" << endl;
    cout << "Total Requests: " << requestCount << endl;
    cout << "========================================\n" << endl;
}

void InstructorMenu::viewMyRequests() {
    cout << "========================================" << endl;
    cout << "      My Requests" << endl;
    cout << "========================================\n" << endl;
    
    vector<InstructorRequest*> myRequests = instructor->getRequests();
    
    if (myRequests.empty()) {
        cout << "You have no pending or submitted requests." << endl;
        return;
    }
    
    cout << "Total Requests: " << myRequests.size() << "\n" << endl;
    
    const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    
    for (size_t i = 0; i < myRequests.size(); ++i) {
        InstructorRequest* req = myRequests[i];
           cout << (i + 1) << ". Lab ID: " << req->getLabId()
               << " | Week: " << req->getWeekNumber()
               << " | Day: " << dayNames[req->getDayOfWeek()] << " (" << req->getDayOfWeek() << ")"
               << " | Time: " << req->getStartHour() << ":" << (req->getStartMin()<10?"0":"") << req->getStartMin()
               << "-" << req->getEndHour() << ":" << (req->getEndMin()<10?"0":"") << req->getEndMin()
               << " | Reason: " << req->getReason()
               << " | Status: " << (req->getIsApproved() ? "Approved" : "Pending") << endl;
    }
    
    cout << "\n========================================" << endl;
}
