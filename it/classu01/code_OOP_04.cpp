#include <iostream>
#include <string>
using namespace std;
int const n = 2;
class student
{
public:
string name;
string group;
int marks[n];
float average;
void getname()
{
cout << "enter name:";getline(cin,name);
}
void getgroup()
{
cout << "enter group:";getline(cin,group);
}
void getmarks()
{
for (int i=0; i<n; i++)
{
    cout << "enter mark[" << i+1 << "]:";cin >> marks[i];
    average+=marks[i];
}
cin.ignore();
average/=n;
}
};
void elementswaps(student& a, student& b)
{
student c;
c.name = a.name;
c.group = a.group;
for (int i=0; i<n; i++)
{
    c.marks[i] = a.marks[i];
}
c.average = a.average;
a.name = b.name;
a.group = b.group;
for (int i=0; i<n; i++)
{
    a.marks[i] = b.marks[i];
}
b.average = c.average;
b.name = c.name;
b.group = c.group;
for (int i=0; i<n; i++)
{
    b.marks[i] = c.marks[i];
}
b.average = c.average;
};
int main()
{
student x[2*n];
for (int i=0; i<2*n;i++)
{
    x[i].getname();
    x[i].getgroup();
    x[i].getmarks();
}
for (int i=0; i<2*n;i++)
{
    for (int j=i+1;j<2*n;j++)
        {
            if(x[j].average<x[i].average)
                elementswaps(x[i],x[j]);
        }
}
char k('y');
cout << "Need to out 4s and 5s? (y/n):";
cin >> k;
if(k=='y')
{
    cout << "output" << endl;
    for (int i=0; i<2*n;i++)
{
    if(x[i].average>=4)
    {
        cout << x[i].name << "\t";
        cout << x[i].group << "\t";
        cout << x[i].average << endl;
    }
}
}
return 0;
}
