#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include "TimeSheet.h"

using namespace std;

class Attendant : public Person {
    private:
        int m_buildingID;

    public:
        Attendant();
        Attendant(int buildingID);
        ~Attendant();

        void setBuildingID(int id);
        int getBuildingID() const;

        void recordTimeSheetEntry(TimeSheet &entry);
};
