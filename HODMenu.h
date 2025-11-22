#pragma once

#include <iostream>
#include <memory>
#include "HeadOfDepartment.h"
#include "LabManagementSystem.h"

class HODMenu {
public:
    HODMenu(LabManagementSystem *system, HeadOfDepartment *hod);
    ~HODMenu();

    void displayMenu();

private:
    LabManagementSystem *m_system;
    HeadOfDepartment *m_hod;

    void viewPendingRequests();
    void approveOrDenyRequest();
    void reportsMenu();
};
