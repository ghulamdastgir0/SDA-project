#pragma once

#include "Person.h"
#include <vector>
#include <string>
#include "TimeSheet.h"


class Attendant : public Person {
    private:
        int buildingID;

    public:
        Attendant(string name, int buildingID, int attendantID);
        ~Attendant();

        void setBuildingID(int id);
        int getBuildingID() const;

        void recordTimeSheetEntry(TimeSheet &entry);
};
