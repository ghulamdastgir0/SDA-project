#pragma once

#include <string>

using namespace std;

class InstructorRequest {
private:
    static int requestID;
    int labID;
    int instructorID;
    int weekNumber;
    char reason[100];
    bool isApproved;
public:
    InstructorRequest();
    InstructorRequest(int labID, int instID, int weekNo, char Reason[100]);
    ~InstructorRequest();

    void ApproveRequest();
    void viewRequestDetails();
};