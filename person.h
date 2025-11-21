#pragma once

#include <string>

using namespace std;

class Person {
    int m_id;
    string m_name;
public:
    Person(int id, string name);
    virtual ~Person();

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);


};