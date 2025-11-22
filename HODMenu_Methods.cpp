#include "HODMenu.h"
#include <iostream>
#include <vector>

using namespace std;

HODMenu::HODMenu(LabManagementSystem *system, HeadOfDepartment *hod)
    : m_system(system), m_hod(hod) {}

HODMenu::~HODMenu() {}

void HODMenu::displayMenu() {
    if (!m_system || !m_hod) return;

    while (true) {
        cout << "\n========================================" << endl;
        cout << "      HOD Menu - " << m_hod->getName() << endl;
        cout << "========================================\n" << endl;
        cout << "1. View Pending Requests" << endl;
        cout << "2. Approve/Deny a Request" << endl;
        cout << "3. Reports" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        int ch = 0;
        if (!(cin >> ch)) { cin.clear(); cin.ignore(10000, '\n'); continue; }
        cin.ignore();
        if (ch == 1) viewPendingRequests();
        else if (ch == 2) approveOrDenyRequest();
        else if (ch == 3) reportsMenu();
        else if (ch == 4) { cout << "Exiting HOD Menu. Goodbye!" << endl; break; }
        else cout << "Invalid choice." << endl;
    }
}

void HODMenu::viewPendingRequests() {
    auto list = m_system->getPendingRequests();
    if (list.empty()) {
        cout << "No requests available." << endl;
        return;
    }
    cout << "\n--- Pending Requests ---" << endl;
    for (size_t i = 0; i < list.size(); ++i) {
        auto r = list[i];
        string status = "Pending";
        if (r->getIsApproved()) status = "Approved";
        else if (r->getIsDenied()) status = "Denied";
        cout << i+1 << ". Lab ID: " << r->getLabId()
             << " | Instructor ID: " << r->getInstructorId()
             << " | Day/Week: " << r->getWeekNumber()
             << " | Reason: " << r->getReason()
             << " | Status: " << status
             << endl;
    }
}

void HODMenu::approveOrDenyRequest() {
    auto list = m_system->getPendingRequests();
    if (list.empty()) { cout << "No requests to process." << endl; return; }
    viewPendingRequests();
    cout << "Enter request number to process: ";
    int id = 0; if (!(cin >> id)) { cin.clear(); cin.ignore(10000,'\n'); return; }
    if (id < 1 || id > (int)list.size()) { cout << "Invalid request number." << endl; return; }
    cout << "Approve or Deny? (a/d): "; char c=' '; cin >> c; cin.ignore();
    bool approve = (c == 'a' || c == 'A');
    bool ok = m_system->processRequest(id, approve);
    if (ok) cout << "Request processed." << endl;
    else cout << "Failed to process request." << endl;
}

void HODMenu::reportsMenu() {
    cout << "\nReports (placeholders):" << endl;
    cout << "1. Complete weekly schedule" << endl;
    cout << "2. Filled timesheets for a week" << endl;
    cout << "3. Timesheet summary for a lab (semester)" << endl;
    cout << "4. Back" << endl;
    cout << "Enter choice: ";
    int ch = 0; if (!(cin >> ch)) { cin.clear(); cin.ignore(10000,'\n'); return; }
    cin.ignore();
    if (ch == 1) {
        // Complete weekly schedule (no week number required)
        cout << "==== Weekly Lab Schedule Report ====" << endl;
        auto schedules = m_system->getWeeklySchedule(0);
        const char* dayNames[] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        if (schedules.empty()) cout << "No scheduled sessions." << endl;
        else {
            for (const auto &s : schedules) {
                cout << "LabSection: " << s.getLabSectionID()
                     << " | Day: " << dayNames[s.getDayOfWeek()] << " | Time: ";
                s.getTiming().print();
                cout << endl;
            }
        }
        cout << "===================================" << endl;
    } else if (ch == 2) {
        int w; cout << "Enter week number: "; if (!(cin >> w)) { cin.clear(); cin.ignore(10000,'\n'); return; }
        cin.ignore();
        cout << "==== Timesheet Report for Week " << w << " ====" << endl;
        auto times = m_system->getFilledTimeSheetsForWeek(w);
        if (times.empty()) cout << "No timesheets found for week " << w << "." << endl;
        else {
            for (const auto &ts : times) {
                cout << "Lab ID: " << ts.getLabID() << " | Day: " << ts.getDayOfWeek() << " | Time: ";
                ts.getTiming().print();
                cout << endl;
            }
        }
        cout << "===================================" << endl;
    } else if (ch == 3) {
        int lab; cout << "Enter lab ID: "; if (!(cin >> lab)) { cin.clear(); cin.ignore(10000,'\n'); return; }
        cin.ignore();
        cout << "==== Lab Session Report for Lab " << lab << " ====" << endl;
        auto times = m_system->getTimeSheetsForLab(lab);
        if (times.empty()) cout << "No timesheets found for lab " << lab << "." << endl;
        else {
            for (const auto &ts : times) {
                cout << "Week: " << ts.getWeekNumber() << " | Day: " << ts.getDayOfWeek() << " | Time: ";
                ts.getTiming().print();
                cout << endl;
            }
        }
        double totalHours = m_system->computeTotalContactHoursForLab(lab);
        int leaves = m_system->computeLeavesForLab(lab);
        cout << "Total contact hours (from schedules): " << totalHours << "\n";
        cout << "Leaves: " << leaves << endl;
        cout << "===================================" << endl;
    } else if (ch == 4) return;
    else cout << "Invalid choice." << endl;
}
