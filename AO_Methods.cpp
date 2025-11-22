#include "AcademicOfficer.h"
#include <iostream>

using namespace std;

// Constructor
AcademicOfficer::AcademicOfficer(int id, string name, int buildingID)
    : Person(id, name), managedBuilding(buildingID)
{
    // suppressed: AcademicOfficer constructor output
}

// Get the managed building ID
int AcademicOfficer::getManagedBuilding() const {
    return managedBuilding;
}

// Add a schedule entry
void AcademicOfficer::addScheduleEntry(const Schedule &entry) {
    // suppressed: academic officer add schedule log
    // TODO: Implementation to store the schedule entry
    // This would typically add to a central schedule manager or database
}

// Modify an existing schedule entry
void AcademicOfficer::modifyScheduleEntry(int scheduleId, const Schedule &entry) {
    // suppressed: academic officer modify schedule log
    // TODO: Implementation to update the schedule entry
    // This would find the schedule by ID and update its fields
}

// Remove a schedule entry
void AcademicOfficer::removeScheduleEntry(int scheduleId) {
    // suppressed: academic officer remove schedule log
    // TODO: Implementation to delete the schedule entry
    // This would remove the schedule from the central manager or database
}

// Review an instructor request
void AcademicOfficer::reviewRequest(const InstructorRequest &request) {
    // suppressed: academic officer review request log
    // TODO: Implementation to examine request details
    // Could log details, notify relevant parties, or prepare for approval/rejection
}

// Approve a request
void AcademicOfficer::approveRequest(int requestId) {
    // suppressed: academic officer approve log
    // TODO: Implementation to mark the request as approved
    // This would update request status and notify relevant parties
}

// Reject a request
void AcademicOfficer::rejectRequest(int requestId) {
    // suppressed: academic officer reject log
    // TODO: Implementation to mark the request as rejected
    // This would update request status and notify the requester with reason
}
