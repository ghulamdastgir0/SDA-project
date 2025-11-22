#include "AttendantMenu.h"
#include <vector>
#include "TimeSheet.h"
#include "Request.h"

using namespace std;

AttendantMenu::AttendantMenu(LabManagementSystem* lms, Attendant* att)
    : m_lms(lms), m_att(att) {}

void AttendantMenu::displayMenu() {
    while (true) {
        cout << "\n--- Attendant Menu ---" << endl;
        cout << "1) Create TimeSheet entry" << endl;
        cout << "2) View TimeSheets for a Lab" << endl;
        cout << "3) View approved instructor requests" << endl;
        cout << "4) Create TimeSheet from approved request" << endl;
        cout << "0) Exit Attendant Menu" << endl;
        cout << "Select option: ";
        int opt = -1;
        if (!(cin >> opt)) {
            if (cin.eof()) break; // EOF -> exit menu gracefully
            cin.clear(); cin.ignore(10000,'\n');
            continue;
        }
        cin.ignore();
        if (opt == 0) break;
        if (opt == 1) {
            int labID, weekNo, dayOfWeek;
            int sHr, eHr, sMin, eMin;
            cout << "Lab ID: "; cin >> labID; cin.ignore();
            cout << "Week number: "; cin >> weekNo; cin.ignore();
            cout << "Day of week (1=Mon..7=Sun): "; cin >> dayOfWeek; cin.ignore();
            cout << "Start hour (0-23): "; cin >> sHr; cin.ignore();
            cout << "Start minute (0-59): "; cin >> sMin; cin.ignore();
            cout << "End hour (0-23): "; cin >> eHr; cin.ignore();
            cout << "End minute (0-59): "; cin >> eMin; cin.ignore();
            Timing t(sHr, sMin, eHr, eMin);
            TimeSheet* ts = m_lms->recordTimeSheet(labID, dayOfWeek, weekNo, t);
            if (ts) cout << "TimeSheet created successfully." << endl;
            else cout << "Failed to create TimeSheet." << endl;
        } else if (opt == 2) {
            int labID; cout << "Lab ID: "; cin >> labID; cin.ignore();
            auto sheets = m_lms->getTimeSheetsForLab(labID);
            if (sheets.empty()) cout << "No timesheets for lab " << labID << endl;
            else {
                for (size_t i = 0; i < sheets.size(); ++i) {
                    const auto &s = sheets[i];
                    cout << i+1 << ". Lab:" << s.getLabID() << " Week:" << s.getWeekNumber()
                         << " Day:" << s.getDayOfWeek() << " Time: ";
                    s.getTiming().print();
                    cout << endl;
                }
            }
        } else if (opt == 3) {
            auto reqs = m_lms->getPendingRequests();
            int printed = 0;
            for (size_t i = 0; i < reqs.size(); ++i) {
                auto r = reqs[i];
                if (r && r->getIsApproved()) {
                    printed++;
                    cout << printed << ". LabID:" << r->getLabId() << " | Instructor:" << r->getInstructorId()
                         << " | Week:" << r->getWeekNumber() << " | Reason:" << r->getReason() << endl;
                }
            }
            if (printed == 0) cout << "No approved requests." << endl;
        } else if (opt == 4) {
            auto reqs = m_lms->getPendingRequests();
            vector<InstructorRequest*> approved;
            for (auto r : reqs) if (r && r->getIsApproved()) approved.push_back(r);
            if (approved.empty()) { cout << "No approved requests to create timesheet from." << endl; continue; }
            for (size_t i = 0; i < approved.size(); ++i) {
                auto r = approved[i];
                cout << i+1 << ". LabID:" << r->getLabId() << " | Instructor:" << r->getInstructorId()
                     << " | Week:" << r->getWeekNumber() << " | Reason:" << r->getReason() << endl;
            }
            cout << "Select request number to create timesheet from: ";
            int sel = 0; cin >> sel; cin.ignore();
            if (sel < 1 || sel > (int)approved.size()) { cout << "Invalid selection." << endl; continue; }
            InstructorRequest* chosen = approved[sel-1];
            int dayOfWeek; int sHr,eHr,sMin,eMin;
            cout << "Enter day of week for timesheet (1=Mon..7=Sun): "; cin >> dayOfWeek; cin.ignore();
            cout << "Start hour: "; cin >> sHr; cin.ignore();
            cout << "Start minute: "; cin >> sMin; cin.ignore();
            cout << "End hour: "; cin >> eHr; cin.ignore();
            cout << "End minute: "; cin >> eMin; cin.ignore();
            Timing t(sHr, sMin, eHr, eMin);
            TimeSheet* ts = m_lms->recordTimeSheet(chosen->getLabId(), dayOfWeek, chosen->getWeekNumber(), t);
            if (ts) cout << "TimeSheet created from approved request." << endl;
            else cout << "Failed to create TimeSheet." << endl;
        } else {
            cout << "Unknown option." << endl;
        }
    }
}
