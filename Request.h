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
    bool isDenied;
public:
    InstructorRequest();
    InstructorRequest(int labID, int instID, int weekNo, string Reason);
    ~InstructorRequest();

    void ApproveRequest();
    void DenyRequest();
    void viewRequestDetails();
    int getInstructorId() const { return instructorID; }
    int getLabId() const { return labID; }
    int getWeekNumber() const { return weekNumber; }
    const std::string& getReason() const { return reason; }
    bool getIsApproved() const { return isApproved; }
    bool getIsDenied() const { return isDenied; }
    void setApproved(bool v) { isApproved = v; isDenied = false; }
    void setDenied(bool v) { isDenied = v; if (v) isApproved = false; }
};
