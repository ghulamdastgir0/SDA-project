#include "Instructor.h"
#include <iostream>

using namespace std;

 Instructor::Instructor(int id, const string &name, const vector<int> &managedLabSectionIDs)
        : Person(id, name)
    {
        managedLabIds = managedLabSectionIDs;
        cout << "Instructor '" << name << "' (ID=" << id << ") initialized with " << managedLabIds.size() << " assigned lab sections." << endl;
    }

Instructor::~Instructor() {
    // clean up requests if owned
    for (auto *r : requests) {
        // requests allocated by createMakeupRequest; free them
        delete r;
    }
    requests.clear();
}

void Instructor::assignLab(LabSection &section) {
    // store pointer to the lab section
    assignedLabs.push_back(&section);
    cout << "Instructor " << getName() << " assigned to lab section at " << &section << "\n";
}

void Instructor::removeAssignedLab(int labId, int sectionNumber) {
    // No direct way to match labId/sectionNumber (LabSection has no public getters here).
    // For now remove the first assigned lab if any and log action.
    if (!assignedLabs.empty()) {
        LabSection* ls = assignedLabs.back();
        assignedLabs.pop_back();
        cout << "Instructor " << getName() << " removed assigned lab section at " << ls << "\n";
    } else {
        cout << "Instructor " << getName() << " has no assigned labs to remove." << endl;
    }
}

vector<LabSection*> Instructor::getAssignedLabs() {
    return assignedLabs;
}

int Instructor::createMakeupRequest(int labId, int weekNumber, const string &reason) {
    // Create a simple InstructorRequest via default constructor and store it.
    InstructorRequest *r = new InstructorRequest();
    requests.push_back(r);
    cout << "Instructor " << getName() << " created makeup request for lab " << labId << " week " << weekNumber << "\n";
    return static_cast<int>(requests.size());
}

vector<InstructorRequest*> Instructor::getRequests() {
    return requests;
}
