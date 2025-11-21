#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class LabSchedule {
public:
    int LabSectionID;
    int DayOfWeek;
    int StartHr;
    int EndHr;
    int StartMin;
    int EndMin;

    void write(fstream &file) {
        file.write((char*)&LabSectionID, sizeof(LabSectionID));
        file.write((char*)&DayOfWeek, sizeof(DayOfWeek));
        file.write((char*)&StartHr, sizeof(StartHr));
        file.write((char*)&EndHr, sizeof(EndHr));
        file.write((char*)&StartMin, sizeof(StartMin));
        file.write((char*)&EndMin, sizeof(EndMin));
    }

    void read(fstream &file) {
        file.read((char*)&LabSectionID, sizeof(LabSectionID));
        file.read((char*)&DayOfWeek, sizeof(DayOfWeek));
        file.read((char*)&StartHr, sizeof(StartHr));
        file.read((char*)&EndHr, sizeof(EndHr));
        file.read((char*)&StartMin, sizeof(StartMin));
        file.read((char*)&EndMin, sizeof(EndMin));
    }

    void print() {
        cout << LabSectionID << " , "
             << DayOfWeek << " , "
             << StartHr << " , "
             << EndHr << " , "
             << StartMin << " , "
             << EndMin << endl;
    }
};

/*
//int main() {

    vector<LabSchedule> schedules = {
        {2001,1,9,11,0,0},{2002,1,11,13,0,0},{2003,1,13,15,0,0},{2004,1,15,17,0,0},
        {2005,1,17,19,0,0},{2006,1,19,21,0,0},{2007,1,8,10,0,0},{2008,1,10,12,0,0},
        {2009,1,12,14,0,0},{2010,1,14,16,0,0},{3001,2,9,11,0,0},{3002,2,11,13,0,0},
        {4001,3,9,11,0,0},{4002,3,11,13,0,0},{5001,4,9,11,0,0},{5002,4,11,13,0,0},
        {5003,4,13,15,0,0},{6001,5,9,11,0,0},{6002,5,11,13,0,0},{7001,6,9,11,0,0},
        {7002,6,11,13,0,0}
    };

    fstream out("../data/labschedule.dat", ios::out | ios::binary);
    for (auto &s : schedules) s.write(out);
    out.close();

    fstream in("../data/labschedule.dat", ios::in | ios::binary);
    while (in.peek() != EOF) {
        LabSchedule s;
        s.read(in);
        if (!in) break;
        s.print();
    }
    in.close();
// commented out main function
}
*/
