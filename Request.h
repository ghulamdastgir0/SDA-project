#pragma once

#include <string>

using namespace std;

class InstructorRequest {
private:
    static int requestID;
    int labID;
    int instructorID;
    int weekNumber;
    string reason;
    bool isApproved;
public:
    InstructorRequest();
    InstructorRequest(int labID, int instID, int weekNo, string Reason);
    ~InstructorRequest();

    void ApproveRequest();
    void viewRequestDetails();
    int getInstructorId() const { return instructorID; }
    int getLabId() const { return labID; }
    int getWeekNumber() const { return weekNumber; }
    const std::string& getReason() const { return reason; }
    bool getIsApproved() const { return isApproved; }
};
