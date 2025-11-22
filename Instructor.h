#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include <vector>
// Forward declarations to avoid circular includes
class LabSection;
class LabManagementSystem;
#include "Request.h"

using namespace std;

class Instructor : public Person {
public:
    // Construct with id, name and list of managed lab section IDs
    Instructor(int id, const string &name, const vector<int> &managedLabSectionIDs);
    ~Instructor();

    void assignLab(int labId);
    void removeAssignedLab(int labId);
    vector<int> getAssignedLabIds() const;

    int createMakeupRequest(class LabManagementSystem &lms, int labId, int weekNumber, int dayOfWeek, int startHour, int startMin, int endHour, int endMin, const string &reason);
    vector<InstructorRequest*> getRequests();
    // Add a non-owning pointer to a request (used when loading persisted requests)
    void addRequestPointer(InstructorRequest* reqPtr);

private:
    vector<int> managedLabIds;
    vector<InstructorRequest*> requests;
};
