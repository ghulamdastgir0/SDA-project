#include "TA.h"
#include <iostream>

using namespace std;

TA::TA(int id, const string &name, const vector<int> &assignedLabSectionIDs)
    : Person(id, name), m_assignedLabs(assignedLabSectionIDs)
{
    // suppressed: TA constructor output for cleaner UI
}

TA::~TA() {
}

void TA::assignToLab(const int &section) {
    m_assignedLabs.push_back(section);
    // suppressed: TA assigned message
}

void TA::removeFromLab(int labId, int sectionNumber) {
    // suppressed: TA removed message
    // TODO: Implementation to remove lab from m_assignedLabs
}

const vector<int> &TA::getAssignedLabs() const {
    return m_assignedLabs;
}
