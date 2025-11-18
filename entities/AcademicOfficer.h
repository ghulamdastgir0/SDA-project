#pragma once

#include "Person.h"
#include <string>
#include <vector>
#include "Schedule.h"
#include "Request.h"
#include "LabSection.h"

using namespace std;

class AcademicOfficer : public Person {
	private:
		int managedBuilding;
	public:
		AcademicOfficer();
		AcademicOfficer(int buildingID);
		~AcademicOfficer();

		void addScheduleEntry(const Schedule &entry);
		void modifyScheduleEntry(int scheduleId, const Schedule &entry);
		void removeScheduleEntry(int scheduleId);

		void reviewRequest(const InstructorRequest &request);
		void approveRequest(int requestId);
		void rejectRequest(int requestId);
};