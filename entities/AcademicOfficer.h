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
		int ID;
		char name[100];
		int managedBuilding;
	public:
		AcademicOfficer(int id, int buildingID);

		void addScheduleEntry(const Schedule &entry);
		void modifyScheduleEntry(int scheduleId, const Schedule &entry);
		void removeScheduleEntry(int scheduleId);

		void reviewRequest(const InstructorRequest &request);
		void approveRequest(int requestId);
		void rejectRequest(int requestId);
};

AcademicOfficer(int id, const char name[100], int buildingID){
	this->ID = id;
	strcpy(this->name, name);
	this->managedBuilding = buildingID;
}

void addScheduleEntry(const Schedule &entry){
	
}