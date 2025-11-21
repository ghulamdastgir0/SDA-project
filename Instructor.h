#pragma once

#include "Person.h"
#include <vector>
#include <string>
// Forward declarations to avoid circular includes
class LabSection;
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

    int createMakeupRequest(int labId, int weekNumber, const string &reason);
    vector<InstructorRequest*> getRequests();

private:
    vector<int> managedLabIds;
    vector<InstructorRequest*> requests;
};
