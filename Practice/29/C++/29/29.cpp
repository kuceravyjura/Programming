#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "BozoSort.h"

using namespace std;

struct student{
    string name;
    short group;
    map<string, short> exams;
    student(std::string name, int group,
        int math, int phys, int hist, int prog);


};



int main()
{
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "+------------+-------+------+------+------+------+" << endl;
    cout << "| Name       | Group | Math | Phys | Hist | Prog |";
    cout << "+------------+-------+------+------+------+------+" << endl;
    vector<student> students{
        student("Lenin W",            3,4,3,5,5),
        student("Kurilovich J",       5,2,2,3,5),
        student("Bezdarev K",         3,4,4,4,4),
        student("Lucifer S",          5,3,4,3,4),
        student("Sigizmund V",        3,4,4,2,2),
        student("Shepard S",          3,5,4,5,3),
        student("Ainz O",             2,5,2,5,4),
        student("Octavios T",         4,3,2,5,5),
    };
    //BozoSort(students,8 , 1); фигово как-то работает

}
