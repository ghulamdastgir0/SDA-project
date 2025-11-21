#include "AcademicOfficer.h"
#include <iostream>

using namespace std;

// Constructor
AcademicOfficer::AcademicOfficer(int id, string name, int buildingID)
    : Person(id, name), managedBuilding(buildingID)
{
    cout << "AcademicOfficer '" << name << "' created for Building ID: " << buildingID << endl;
}

// Get the managed building ID
int AcademicOfficer::getManagedBuilding() const {
    return managedBuilding;
}

// Add a schedule entry
void AcademicOfficer::addScheduleEntry(const Schedule &entry) {
    cout << "AcademicOfficer " << getName() << " adding schedule entry." << endl;
    // TODO: Implementation to store the schedule entry
    // This would typically add to a central schedule manager or database
}

// Modify an existing schedule entry
void AcademicOfficer::modifyScheduleEntry(int scheduleId, const Schedule &entry) {
    cout << "AcademicOfficer " << getName() << " modifying schedule entry ID: " << scheduleId << endl;
    // TODO: Implementation to update the schedule entry
    // This would find the schedule by ID and update its fields
}

// Remove a schedule entry
void AcademicOfficer::removeScheduleEntry(int scheduleId) {
    cout << "AcademicOfficer " << getName() << " removing schedule entry ID: " << scheduleId << endl;
    // TODO: Implementation to delete the schedule entry
    // This would remove the schedule from the central manager or database
}

// Review an instructor request
void AcademicOfficer::reviewRequest(const InstructorRequest &request) {
    cout << "AcademicOfficer " << getName() << " reviewing request from Instructor ID: " 
         << request.getInstructorId() << endl;
    // TODO: Implementation to examine request details
    // Could log details, notify relevant parties, or prepare for approval/rejection
}

// Approve a request
void AcademicOfficer::approveRequest(int requestId) {
    cout << "AcademicOfficer " << getName() << " approving request ID: " << requestId << endl;
    // TODO: Implementation to mark the request as approved
    // This would update request status and notify relevant parties
}

// Reject a request
void AcademicOfficer::rejectRequest(int requestId) {
    cout << "AcademicOfficer " << getName() << " rejecting request ID: " << requestId << endl;
    // TODO: Implementation to mark the request as rejected
    // This would update request status and notify the requester with reason
}
