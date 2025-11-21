#include "Instructor.h"
#include <iostream>
#include <algorithm>

using namespace std;

Instructor::Instructor(int id, const string &name, const vector<int> &managedLabSectionIDs)
    : Person(id, name), managedLabIds(managedLabSectionIDs)
{
    cout << "Instructor '" << name << "' (ID=" << id << ") initialized with " << managedLabIds.size() << " assigned lab IDs." << endl;
}

Instructor::~Instructor() {
    // clean up requests if owned
    for (auto *r : requests) {
        // requests allocated by createMakeupRequest; free them
        delete r;
    }
    requests.clear();
}

void Instructor::assignLab(int labId) {
    // store the lab ID
    managedLabIds.push_back(labId);
    cout << "Instructor " << getName() << " assigned to lab ID: " << labId << "\n";
}

void Instructor::removeAssignedLab(int labId) {
    // Find and remove the lab ID from the vector
    auto it = find(managedLabIds.begin(), managedLabIds.end(), labId);
    if (it != managedLabIds.end()) {
        managedLabIds.erase(it);
        cout << "Instructor " << getName() << " removed lab ID: " << labId << "\n";
    } else {
        cout << "Instructor " << getName() << " is not assigned to lab ID " << labId << "." << endl;
    }
}

vector<int> Instructor::getAssignedLabIds() const {
    return managedLabIds;
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
