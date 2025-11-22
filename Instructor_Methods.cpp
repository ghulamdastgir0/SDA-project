#include "Instructor.h"
#include "LabManagementSystem.h"
#include <iostream>
#include <algorithm>

using namespace std;

Instructor::Instructor(int id, const string &name, const vector<int> &managedLabSectionIDs)
    : Person(id, name), managedLabIds(managedLabSectionIDs)
{
    // suppressed: Instructor constructor output for cleaner UI
}

Instructor::~Instructor() {
    // Requests are owned by LabManagementSystem (stored as unique_ptr there).
    // Do not delete the raw pointers here; just clear the tracking list.
    requests.clear();
}

void Instructor::assignLab(int labId) {
    // store the lab ID
    managedLabIds.push_back(labId);
}

void Instructor::removeAssignedLab(int labId) {
    // Find and remove the lab ID from the vector
    auto it = find(managedLabIds.begin(), managedLabIds.end(), labId);
    if (it != managedLabIds.end()) {
        managedLabIds.erase(it);
        // suppressed: instructor lab removal message
    } else {
        // suppressed: instructor not assigned message
    }
}

vector<int> Instructor::getAssignedLabIds() const {
    return managedLabIds;
}

int Instructor::createMakeupRequest(LabManagementSystem &lms, int labId, int weekNumber, const string &reason) {
    // Submit the request through the LabManagementSystem which owns the request.
    InstructorRequest *r = lms.submitInstructorRequest(getId(), labId, weekNumber, reason);
    if (r) {
        requests.push_back(r);
        cout << "Instructor " << getName() << " submitted makeup request for lab " << labId
             << " week " << weekNumber << "\n";
    } else {
        cout << "Instructor " << getName() << " failed to submit makeup request for lab " << labId << "\n";
    }
    return static_cast<int>(requests.size());
}

vector<InstructorRequest*> Instructor::getRequests() {
    return requests;
}
