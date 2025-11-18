#pragma once

#include <iostream>
#include <iomanip>

class Timing {
private:
    int startHour, startMin;
    int endHour, endMin;

public:
    Timing() : startHour(0), startMin(0), endHour(0), endMin(0) {}

    Timing(int sh, int sm, int eh, int em) {
        setStartTime(sh, sm);
        setEndTime(eh, em);
    }

    void setStartTime(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            startHour = h;
            startMin = m;
        } else {
            std::cout << "Invalid start time!\n";
        }
    }

    void setEndTime(int h, int m) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60) {
            endHour = h;
            endMin = m;
        } else {
            std::cout << "Invalid end time!\n";
        }
    }

    int getStartHour() const { return startHour; }
    int getStartMin() const { return startMin; }
    int getEndHour() const { return endHour; }
    int getEndMin() const { return endMin; }

    int startInMinutes() const { return startHour * 60 + startMin; }
    int endInMinutes() const { return endHour * 60 + endMin; }

    int getDuration() const {
        return endInMinutes() - startInMinutes();
    }

    bool equals(const Timing& t) const {
        return startHour == t.startHour &&
               startMin == t.startMin &&
               endHour == t.endHour &&
               endMin == t.endMin;
    }

    bool overlaps(const Timing& t) const {
        return !(endInMinutes() <= t.startInMinutes() ||
                 t.endInMinutes() <= startInMinutes());
    }

    void print() const {
        std::cout << std::setfill('0')
                  << std::setw(2) << startHour << ":"
                  << std::setw(2) << startMin  << " - "
                  << std::setw(2) << endHour << ":"
                  << std::setw(2) << endMin  << "\n";
    }
};
