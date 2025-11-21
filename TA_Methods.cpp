#include "TA.h"
#include <iostream>

using namespace std;

TA::TA() : Person(0, "") {
    cout << "TA created." << endl;
}

TA::~TA() {
    cout << "TA with ID " << getId() << " destroyed." << endl;
}

void TA::assignToLab(const LabSection &section) {
    m_assignedLabs.push_back(section);
    cout << "TA " << getId() << " assigned to lab section." << endl;
}

void TA::removeFromLab(int labId, int sectionNumber) {
    cout << "TA " << getId() << " removed from lab section." << endl;
    // TODO: Implementation to remove lab from m_assignedLabs
}

const vector<LabSection> &TA::getAssignedLabs() const {
    return m_assignedLabs;
}
