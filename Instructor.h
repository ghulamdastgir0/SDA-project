#pragma once

#include "Person.h"
#include <vector>
#include <string>
// Forward declarations to avoid circular includes
class LabSection;
#include "Request.h"

using namespace std;

class Instructor : public Person {
    vector<int> managedLabIds;
public:
    // Construct with id, name and list of managed lab section IDs
    Instructor(int id, const string &name, const vector<int> &managedLabSectionIDs);
    ~Instructor();

    void assignLab(LabSection &section);
    void removeAssignedLab(int labId, int sectionNumber);
    vector<LabSection*> getAssignedLabs();

    int createMakeupRequest(int labId, int weekNumber, const string &reason);
    vector<InstructorRequest*> getRequests();

private:
    vector<LabSection*> assignedLabs;
    vector<InstructorRequest*> requests;
};
