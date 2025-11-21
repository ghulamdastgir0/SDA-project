#pragma once

#include <string>
#include "LabSection.h"

class Lab{
private:
    int labID;
    char labCode[50];
    string labName;
    vector<LabSection> sections;
public:
    Lab();
    Lab(int ID,string code, string name);
    ~Lab();

    int getID();
    void setID(int ID);

    string getName();
    void setName(string name);
};