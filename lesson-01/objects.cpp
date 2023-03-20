#include <iostream>
using namespace std;

class Building {
public:
    int number;
    string adress;
    string university;
};

class Student {
public:
    int age;
    string name;
    string course;
    int semester;
};

class Computer {
public:
    int date;
    string software;
    string type;
};

int main() {
    Building elektryk;
    elektryk.number = 3;
    elektryk.adress = "Piotrowo";
    elektryk.university = "PUT";

    Student me;
    me.age = 19;
    me.name = "Julia";
    me.semester = 2;
    me.course = "bioinformatics";

    Computer thiscomputer;
    thiscomputer.date = 2018;
    thiscomputer.software = "Windows";
    thiscomputer.type = "Desktop";

    cout << "This computer:" << endl;
    cout << thiscomputer.software << " ";
    cout << thiscomputer.date << endl;
    cout << thiscomputer.type << endl;
    cout << "Used by: ";
    cout << me.name << endl;
    cout << "Located in building number: ";
    cout << elektryk.number;
}
