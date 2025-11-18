#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include "LabSection.h"

using namespace std;

class TA : public Person {
public:
    TA();
    ~TA();

    void assignToLab(const LabSection &section);
    void removeFromLab(int labId, int sectionNumber);
    const vector<LabSection> &getAssignedLabs() const;

private:
    vector<LabSection> m_assignedLabs;
};