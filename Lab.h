#pragma once

#include <string>
#include "LabSection.h"

class Lab{
private:
    int labID;
    string labCode;
    string labName;
    vector<LabSection> sections;
public:
    Lab(int ID, string code, string name, vector<LabSection> sections);
    ~Lab();

    int getID();
    void setID(int ID);

    string getCode();
    void setCode(string code);

    string getName();
    void setName(string name);
};