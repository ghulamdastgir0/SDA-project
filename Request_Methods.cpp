#include "Request.h"
#include <iostream>

using namespace std;

// Default constructor
InstructorRequest::InstructorRequest()
    : labID(0), instructorID(0), weekNumber(0), isApproved(false), reason("")
{
}

// Parameterized constructor
InstructorRequest::InstructorRequest(int lab, int instID, int weekNo, string Reason)
    : labID(lab), instructorID(instID), weekNumber(weekNo), isApproved(false), reason(Reason)
{
    ++InstructorRequest::requestID;
}

// Destructor
InstructorRequest::~InstructorRequest() {
    cout << "InstructorRequest (Lab ID: " << labID << ", Instructor ID: " << instructorID << ") destroyed." << endl;
}

// Approve the request
void InstructorRequest::ApproveRequest() {
    isApproved = true;
    cout << "Request from Instructor " << instructorID << " for Lab " << labID << " approved." << endl;
}

void InstructorRequest::viewRequestDetails() {
    cout << "Request ID: " << requestID << ", Lab ID: " << labID << ", Instructor ID: " 
         << instructorID << ", Week: " << weekNumber << ", Approved: " << isApproved << endl;
}
