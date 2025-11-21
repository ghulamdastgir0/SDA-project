#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class TA {
public:
    int TAID;
    string Name;
    vector<int> AssignedLabSectionIDs;

    void write(fstream &file) {
        file.write((char*)&TAID, sizeof(TAID));

        int len = Name.size();
        file.write((char*)&len, sizeof(len));
        file.write(Name.c_str(), len);

        int count = AssignedLabSectionIDs.size();
        file.write((char*)&count, sizeof(count));
        for (int id : AssignedLabSectionIDs)
            file.write((char*)&id, sizeof(id));
    }

    void read(fstream &file) {
        file.read((char*)&TAID, sizeof(TAID));

        int len;
        file.read((char*)&len, sizeof(len));
        Name.resize(len);
        file.read(&Name[0], len);

        int count;
        file.read((char*)&count, sizeof(count));
        AssignedLabSectionIDs.resize(count);
        for (int i = 0; i < count; i++)
            file.read((char*)&AssignedLabSectionIDs[i], sizeof(int));
    }

    void print() {
        cout << TAID << " , " << Name << " , [";
        for (int i = 0; i < AssignedLabSectionIDs.size(); i++) {
            cout << AssignedLabSectionIDs[i];
            if (i + 1 < AssignedLabSectionIDs.size()) cout << ",";
        }
        cout << "]\n";
    }
};

int main() {
    vector<TA> list = {
        {4001, "Alex Martin", {2001,2002}},
        {4002, "Brian Lopez", {2003}},
        {4003, "Chloe Kim", {2004}},
        {4004, "David Green", {2005}},
        {4005, "Ella Foster", {2006}},
        {4006, "Frank Turner", {2007}},
        {4007, "Grace Lee", {2008}},
        {4008, "Harry Patel", {2009,2010}},
        {4009, "Rayan Ahmed", {3001,3002}},
        {4010, "Liam Hughes", {4001,4002}},
        {4011, "Dawood Shahzad", {5001,5002,5003}},
        {4012, "Quinn Delgado", {6001}},
        {4013, "Ruby Chen", {6002}},
        {4014, "Steven Young", {7001}},
        {4015, "Tara Mitchell", {7002}}
    };

    fstream file("../data/ta.dat", ios::out | ios::binary);
    for (auto &t : list) t.write(file);
    file.close();

    fstream in("../data/ta.dat", ios::in | ios::binary);

    while (true) {
        TA t;
        if (!in.read((char*)&t.TAID, sizeof(t.TAID))) break;

        int len;
        in.read((char*)&len, sizeof(len));
        t.Name.resize(len);
        in.read(&t.Name[0], len);

        int count;
        in.read((char*)&count, sizeof(count));
        t.AssignedLabSectionIDs.resize(count);
        for (int i = 0; i < count; i++)
            in.read((char*)&t.AssignedLabSectionIDs[i], sizeof(int));

        t.print();
    }

    in.close();
}
