#include "Request.h"
#include <iostream>

using namespace std;

// Default constructor
InstructorRequest::InstructorRequest()
    : labID(-1), instructorID(-1), weekNumber(-1), isApproved(false), isDenied(false), reason("") {
    ++InstructorRequest::requestID;
}

// Parameterized constructor
InstructorRequest::InstructorRequest(int lab, int instID, int weekNo, int dayOfWeek_, int sHr, int sMin, int eHr, int eMin, string Reason)
    : labID(lab), instructorID(instID), weekNumber(weekNo), dayOfWeek(dayOfWeek_), startHour(sHr), startMin(sMin), endHour(eHr), endMin(eMin), isApproved(false), isDenied(false), reason(Reason)
{
    ++InstructorRequest::requestID;
}

// Destructor
InstructorRequest::~InstructorRequest() {
    // suppressed: request destructor output
}

// Approve the request
void InstructorRequest::ApproveRequest() {
    isApproved = true;
    isDenied = false;
}

void InstructorRequest::DenyRequest() {
    isDenied = true;
    isApproved = false;
}

void InstructorRequest::viewRequestDetails() {
        cout << "Request ID: " << requestID << ", Lab ID: " << labID << ", Instructor ID: " 
            << instructorID << ", Week: " << weekNumber << ", Day: " << dayOfWeek
            << ", Time: " << startHour << ":" << startMin << "-" << endHour << ":" << endMin
            << ", Approved: " << isApproved << ", Denied: " << isDenied << endl;
}
