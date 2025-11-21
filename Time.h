#pragma once

#include <string>

class Timing {
private:
    int startHour, startMin;
    int endHour, endMin;

public:
    Timing();
    Timing(int sh, int sm, int eh, int em);

    void setStartTime(int h, int m);
    void setEndTime(int h, int m);

    int getStartHour() const;
    int getStartMin() const;
    int getEndHour() const;
    int getEndMin() const;

    int startInMinutes() const;
    int endInMinutes() const;

    int getDuration() const;

    bool equals(const Timing& t) const;
    bool overlaps(const Timing& t) const;

    void print() const;
};
