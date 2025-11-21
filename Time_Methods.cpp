#include "Time.h"
#include <iostream>
#include <iomanip>

using namespace std;


Timing::Timing(int sh, int sm, int eh, int em)
    : startHour(0), startMin(0), endHour(0), endMin(0)
{
    setStartTime(sh, sm);
    setEndTime(eh, em);
}

void Timing::setStartTime(int h, int m) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60) {
        startHour = h;
        startMin = m;
    } else {
        std::cout << "Invalid start time!\n";
    }
}

void Timing::setEndTime(int h, int m) {
    if (h >= 0 && h < 24 && m >= 0 && m < 60) {
        endHour = h;
        endMin = m;
    } else {
        std::cout << "Invalid end time!\n";
    }
}

int Timing::getStartHour() const { return startHour; }
int Timing::getStartMin() const { return startMin; }
int Timing::getEndHour() const { return endHour; }
int Timing::getEndMin() const { return endMin; }

int Timing::startInMinutes() const { return startHour * 60 + startMin; }
int Timing::endInMinutes() const { return endHour * 60 + endMin; }

int Timing::getDuration() const {
    return endInMinutes() - startInMinutes();
}

bool Timing::equals(const Timing& t) const {
    return startHour == t.startHour &&
           startMin == t.startMin &&
           endHour == t.endHour &&
           endMin == t.endMin;
}

bool Timing::overlaps(const Timing& t) const {
    return !(endInMinutes() <= t.startInMinutes() ||
             t.endInMinutes() <= startInMinutes());
}

void Timing::print() const {
    cout << setfill('0')
             << setw(2) << startHour << ":"
             << setw(2) << startMin  << " - "
             << setw(2) << endHour << ":"
             << setw(2) << endMin  << "\n";
}
