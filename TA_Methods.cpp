#include "TA.h"
#include <iostream>

using namespace std;

TA::TA(int id, const string &name, const vector<int> &assignedLabSectionIDs)
    : Person(id, name), m_assignedLabs(assignedLabSectionIDs)
{
    cout << "TA '" << name << "' (ID=" << id << ") initialized with " << m_assignedLabs.size() << " assigned lab sections." << endl;
}

TA::~TA() {
}

void TA::assignToLab(const int &section) {
    m_assignedLabs.push_back(section);
    cout << "TA " << getId() << " assigned to lab section." << endl;
}

void TA::removeFromLab(int labId, int sectionNumber) {
    cout << "TA " << getId() << " removed from lab section." << endl;
    // TODO: Implementation to remove lab from m_assignedLabs
}

const vector<int> &TA::getAssignedLabs() const {
    return m_assignedLabs;
}
