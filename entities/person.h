#pragma once

#include <string>

using namespace std;

class Person {
    	int ID;
		char name[100];
public:
    Person();
    Person(int id, char name[100]);
    virtual ~Person();

    int getId() const;
    void setId(int id);

    const string &getName() const;
    void setName(const string &name);

    const string &getEmail() const;
    void setEmail(const string &email);


private:
    int m_id;
    string m_name;
    string m_email;
};