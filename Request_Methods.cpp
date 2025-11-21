#include "Request.h"
#include <iostream>
#include <cstring>

using namespace std;

// Default constructor
InstructorRequest::InstructorRequest()
    : labID(0), instructorID(0), weekNumber(0), isApproved(false)
{
    reason[0] = '\0';
}

// Parameterized constructor
InstructorRequest::InstructorRequest(int lab, int instID, int weekNo, char Reason[100])
    : labID(lab), instructorID(instID), weekNumber(weekNo), isApproved(false)
{
    // Safely copy reason (ensure null-termination)
    if (Reason) {
        std::strncpy(reason, Reason, sizeof(reason)-1);
        reason[sizeof(reason)-1] = '\0';
    } else {
        reason[0] = '\0';
    }
    // bump static counter for tracking (optional)
    ++InstructorRequest::requestID;
}

// Approve the request
void InstructorRequest::ApproveRequest() {
    isApproved = true;
    cout << "InstructorRequest approved for lab " << labID << " (instructor " << instructorID << ")" << endl;
}

// Display details
void InstructorRequest::viewRequestDetails() {
    cout << "Request Details:\n";
    cout << "  Lab ID: " << labID << "\n";
    cout << "  Instructor ID: " << instructorID << "\n";
    cout << "  Week: " << weekNumber << "\n";
    cout << "  Reason: " << reason << "\n";
    cout << "  Approved: " << (isApproved ? "Yes" : "No") << "\n";
}
