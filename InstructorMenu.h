#pragma once

#include "LabManagementSystem.h"
#include "Instructor.h"
#include <iostream>

using namespace std;

class InstructorMenu {
private:
    LabManagementSystem* lms;
    Instructor* instructor;

public:
    InstructorMenu(LabManagementSystem* system, Instructor* instr) 
        : lms(system), instructor(instr) {}

    void displayMenu();
    void viewLabSchedules();
    void viewTimesheets();
    void addRequest();
    void viewMyRequests();
};
