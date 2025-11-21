#include "TA.h"
#include <iostream>

using namespace std;

TA::TA() {
}

TA::~TA() {
    m_assignedLabs.clear();
}

void TA::assignToLab(const LabSection &section) {
    m_assignedLabs.push_back(section);
    cout << "TA " << getName() << " assigned to lab section." << endl;
}

void TA::removeFromLab(int labId, int sectionNumber) {
    if (!m_assignedLabs.empty()) {
        m_assignedLabs.pop_back();
        cout << "TA " << getName() << " removed from a lab section." << endl;
    }
}

const vector<LabSection> &TA::getAssignedLabs() const {
    return m_assignedLabs;
}
