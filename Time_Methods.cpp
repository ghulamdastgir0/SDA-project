#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Default constructor
Timing::Timing() : startHour(0), startMin(0), endHour(0), endMin(0) {}

// Parameterized constructor
Timing::Timing(int sh, int sm, int eh, int em) 
    : startHour(sh), startMin(sm), endHour(eh), endMin(em) {}

void Timing::setStartTime(int h, int m) {
    startHour = h;
    startMin = m;
}

void Timing::setEndTime(int h, int m) {
    endHour = h;
    endMin = m;
}

int Timing::getStartHour() const { return startHour; }
int Timing::getStartMin() const { return startMin; }
int Timing::getEndHour() const { return endHour; }
int Timing::getEndMin() const { return endMin; }

int Timing::startInMinutes() const {
    return startHour * 60 + startMin;
}

int Timing::endInMinutes() const {
    return endHour * 60 + endMin;
}

int Timing::getDuration() const {
    return endInMinutes() - startInMinutes();
}

bool Timing::equals(const Timing& t) const {
    return startHour == t.startHour && startMin == t.startMin &&
           endHour == t.endHour && endMin == t.endMin;
}

bool Timing::overlaps(const Timing& t) const {
    return startInMinutes() < t.endInMinutes() && endInMinutes() > t.startInMinutes();
}

void Timing::print() const {
    cout << setfill('0');
    cout << setw(2) << startHour << ":" << setw(2) << startMin << " - "
         << setw(2) << endHour << ":" << setw(2) << endMin;
}
