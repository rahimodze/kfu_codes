#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;
struct student
{
    string name;
    string group;
    int ses[5];
};

int main()
{
setlocale(LC_ALL, "rus");
student *stud = new student[10];
ifstream o("file.txt");
for (int i=0;i<10;i++)
{
    o >> (stud + i)->name;
    cout << "Name:" << (stud + i)->name << endl;
    o >> (stud + i)->group;
    cout << "Group:" << (stud + i)->group << endl;
        for (int j=0;j<5;j++)
        {
            o >> (stud+i)->ses[j];
            cout << "Ses[" << i <<"]" << "[" << j << "]" << (stud+i)->ses[j] << endl;
        }
}
ofstream f("out.txt");
for (int i=0;i<10;i++)
{
    f << (stud+i)->name << "\t";
    f << (stud+i)->group << "\t";
    for (int j=0;j<5;j++)
    {
        f << (stud+i)->ses[j] << "\t";
        }
    f << "\n";
}
    return 0;
}
