#pragma once

#include <string>
#include <vector>
#include <memory>
#include "LabSection.h"

using namespace std;

class Lab{
private:
    int labID;
    string labCode;
    string labName;
    vector<unique_ptr<LabSection>> sections;
public:
    Lab(int ID, string code, string name);
    ~Lab();

    int getID() const;
    void setID(int ID);

    string getCode() const;
    void setCode(string code);

    string getName() const;
    void setName(string name);

    void addSection(unique_ptr<LabSection> section);
    const vector<unique_ptr<LabSection>>& getSections() const;
    int getSectionCount() const;
};