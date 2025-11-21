#pragma once

#include "Person.h"
#include <vector>
#include <string>

using namespace std;

class TA : public Person {
public:
    TA(int id, const string &name, const vector<int> &assignedLabSectionIDs);
    ~TA();

    void assignToLab(const int &section);
    void removeFromLab(int labId, int sectionNumber);
    const vector<int> &getAssignedLabs() const;

private:
    vector<int> m_assignedLabs;
};