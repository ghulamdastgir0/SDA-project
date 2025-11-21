#include "person.h"
#include <iostream>

using namespace std;

Person::Person(int id, string name)
    : m_id(id), m_name(move(name))
{
    // constructor
}

Person::~Person() {
    // virtual destructor
}

int Person::getId() const {
    return m_id;
}

void Person::setId(int id) {
    m_id = id;
}

const string &Person::getName() const {
    return m_name;
}

void Person::setName(const string &name) {
    m_name = name;
}
