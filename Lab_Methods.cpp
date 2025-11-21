#include "Lab.h"
#include <iostream>

using namespace std;

Lab::Lab(int ID, string code, string name)
    : labID(ID), labCode(code), labName(name), sections()
{
    cout << "Lab '" << labName << "' (Code=" << labCode << ", ID=" << labID << ") created." << endl;
}

Lab::~Lab() {
    // unique_ptr will automatically delete sections
    sections.clear();
}

int Lab::getID() const {
    return labID;
}

void Lab::setID(int ID) {
    labID = ID;
}

string Lab::getCode() const {
    return labCode;
}

void Lab::setCode(string code) {
    labCode = code;
}

string Lab::getName() const {
    return labName;
}

void Lab::setName(string name) {
    labName = name;
}

void Lab::addSection(unique_ptr<LabSection> section) {
    sections.push_back(move(section));
}

const vector<unique_ptr<LabSection>>& Lab::getSections() const {
    return sections;
}

int Lab::getSectionCount() const {
    return sections.size();
}
