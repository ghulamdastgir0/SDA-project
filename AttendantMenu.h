#pragma once

#include <iostream>
#include "LabManagementSystem.h"
#include "Attendant.h"

class AttendantMenu {
private:
    LabManagementSystem* m_lms;
    Attendant* m_att;
public:
    AttendantMenu(LabManagementSystem* lms, Attendant* att);
    void displayMenu();
};
