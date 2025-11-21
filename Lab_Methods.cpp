#include "Lab.h"
#include <iostream>

using namespace std;

Lab::Lab(int ID, string code, string name, vector<LabSection> sections)
    : labID(ID), labCode(code), labName(name), sections(sections)
{
    cout << "Lab '" << labName << "' (Code=" << labCode << ", ID=" << labID << ") created." << endl;
}

Lab::~Lab() {
    // clear sections; assume ownership not required to delete contained LabSection objects
    sections.clear();
    cout << "Lab '" << labName << "' destroyed." << endl;
}

int Lab::getID() {
    return labID;
}

void Lab::setID(int ID) {
    labID = ID;
}

string Lab::getCode() {
    return labCode;
}

void Lab::setCode(string code) {
    labCode = code;
}

string Lab::getName() {
    return labName;
}

void Lab::setName(string name) {
    labName = name;
}
