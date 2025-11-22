#pragma once

#include <string>

using namespace std;

class InstructorRequest {
private:
    static int requestID;
    int labID;
    int instructorID;
    int weekNumber;
    int dayOfWeek; // 1..7
    int startHour;
    int startMin;
    int endHour;
    int endMin;
    string reason;
    bool isApproved;
    bool isDenied;
public:
    InstructorRequest();
    InstructorRequest(int labID, int instID, int weekNo, int dayOfWeek, int sHr, int sMin, int eHr, int eMin, string Reason);
    ~InstructorRequest();

    void ApproveRequest();
    void DenyRequest();
    void viewRequestDetails();
    int getInstructorId() const { return instructorID; }
    int getLabId() const { return labID; }
    int getWeekNumber() const { return weekNumber; }
    int getDayOfWeek() const { return dayOfWeek; }
    int getStartHour() const { return startHour; }
    int getStartMin() const { return startMin; }
    int getEndHour() const { return endHour; }
    int getEndMin() const { return endMin; }
    const std::string& getReason() const { return reason; }
    bool getIsApproved() const { return isApproved; }
    bool getIsDenied() const { return isDenied; }
    void setApproved(bool v) { isApproved = v; isDenied = false; }
    void setDenied(bool v) { isDenied = v; if (v) isApproved = false; }
};
