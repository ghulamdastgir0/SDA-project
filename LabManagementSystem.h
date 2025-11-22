#include <iostream>
#pragma once

#include <string>
#include <vector>
#include <memory>

#include "Person.h"
#include "AcademicOfficer.h"
#include "Attendant.h"
#include "Instructor.h"
#include "TA.h"
#include "HeadOfDepartment.h"
#include "Building.h"
#include "Lab.h"
#include "LabSection.h"
#include "Schedule.h"
#include "TimeSheet.h"
#include "Request.h"

using namespace std;

class LabManagementSystem {
public:
    LabManagementSystem();
    ~LabManagementSystem();

    // --- Person management (main ownership)
    AcademicOfficer* addAcademicOfficer(const string &name, const string &email);
    Attendant* addAttendant(const string &name, const string &email, int buildingID = -1);
    Instructor* addInstructor(const string &name, const string &email);
    TA* addTA(const string &name, const string &email);
    HeadOfDepartment* addHeadOfDepartment(const string &name, const string &email);

    bool removeAcademicOfficer(int id);
    bool removeAttendant(int id);
    bool removeInstructor(int id);
    bool removeTA(int id);
    bool removeHeadOfDepartment(int id);

    Person* getPersonById(int id) const;

    // --- Building management
    Building* addBuilding(const string &name);
    bool removeBuilding(int buildingId);
    Building* getBuildingById(int buildingId) const;

    // --- Lab / section management
    Lab* createLab(const string &labName);
    LabSection* createLabSection(int labId, Room* room, const string &courseCode, Instructor* instr, const vector<TA*> &tas);

    // --- Scheduling and timesheets
    Schedule* addScheduleEntry(int labId, int dayOfWeek, int weekNo, const Timing &time);
    TimeSheet* recordTimeSheet(int labId, int dayOfWeek, int weekNo, const Timing &time);

    // --- Requests
    InstructorRequest* submitInstructorRequest(int instructorId, int labId, int weekNumber, int dayOfWeek, int startHour, int startMin, int endHour, int endMin, const string &reason);
    bool processRequest(int requestId, bool approve);

    // --- High-level operations / reports (delegates to other managers / classes)
    vector<Schedule> getWeeklySchedule(int weekNumber) const;
    vector<TimeSheet> getFilledTimeSheetsForWeek(int weekNumber) const;
    vector<TimeSheet> getTimeSheetsForLab(int labId) const;
    double computeTotalContactHoursForLab(int labId) const;
    int computeLeavesForLab(int labId) const;

    void run();

    //reading buildings.dat
    void loadBuildingsFromFile();
    void writeBuildingsToFile();
    void printBuildings() const;

    //reading academic_officers.dat
    void loadAcademicOfficersFromFile();
    void writeAcademicOfficersToFile();
    void printAcademicOfficers() const;

    //reading attendants.dat
    void loadAttendantsFromFile();
    void writeAttendantsToFile();
    void printAttendants() const;

    //reading hods.dat
    void loadHODsFromFile();
    void writeHODsToFile();
    void printHODs() const;

    //reading tas.dat
    void loadTAsFromFile();
    void writeTAsToFile();
    void printTAs() const;

    //reading instructors.dat
    void loadInstructorsFromFile();
    void writeInstructorsToFile();
    void printInstructors() const;

    //reading rooms.dat
    void loadRoomsFromFile();
    void writeRoomsToFile();
    void printRooms() const;

    //reading labs.dat
    void loadLabsFromFile();
    void writeLabsToFile();
    void printLabs() const;

    //reading lab_sections.dat
    void loadLabSectionsFromFile();
    void writeLabSectionsToFile();
    void printLabSections() const;

    //reading schedules.dat
    void loadSchedulesFromFile();
    void writeSchedulesToFile();
    void printSchedules() const;

    //reading pendingRequest.dat
    void loadPendingRequestsFromFile();
    // reading/writing timesheets
    void loadTimeSheetsFromFile();
    // expose pending requests for menus (non-owning raw pointers)
    std::vector<InstructorRequest*> getPendingRequests() const;

private:
    // Owned collections
    vector<unique_ptr<AcademicOfficer>> m_academicOfficers;
    vector<unique_ptr<Attendant>> m_attendants;
    vector<unique_ptr<Instructor>> m_instructors;
    vector<unique_ptr<TA>> m_tas;
    vector<unique_ptr<HeadOfDepartment>> m_hods;

    vector<unique_ptr<Building>> m_buildings;
    vector<unique_ptr<Lab>> m_labs;
    vector<unique_ptr<LabSection>> m_labSections;
    vector<unique_ptr<Schedule>> m_schedules;
    vector<unique_ptr<TimeSheet>> m_timeSheets;
    vector<unique_ptr<InstructorRequest>> m_requests;
    
    // Rooms are owned by buildings, not stored separately here

    // Helper lookups (optional) - kept as raw pointers to objects owned above
    AcademicOfficer* findAcademicOfficerById(int id) const;
    Attendant* findAttendantById(int id) const;
    Instructor* findInstructorById(int id) const;
    TA* findTAById(int id) const;
    HeadOfDepartment* findHODById(int id) const;
    Building* findBuildingByIdInternal(int id) const;

};
