#pragma once
#include "Person.h"

class Attendant : public Person {
public:
    int buildingID;     // which building this attendant is responsible for
};
