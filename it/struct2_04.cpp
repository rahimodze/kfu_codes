#include <iostream>
#include <time.h>
#include <conio.h>
struct date
{
int day;
int month;
int year;
};
using namespace std;
void display(date c1)
{
    cout << c1.day << "." << c1.month << "." << c1.year;
}

int main()
{
srand(time(0));
setlocale(0,"");
int n = 5;
date x[n];
cout << "���� ���.\n";
for (int i=0; i<n; i++)
{
    cout << "���� �" << i+1 << endl;
    x[i].day = 1 + rand()%29;
    cout << "����:" << x[i].day << endl;
    x[i].month = 1 +rand()%11;
    cout << "�����:" << x[i].month << endl;
    x[i].year = 1 +rand()%2021;
    cout << "���:" << x[i].year << endl;
    display(x[i]);
    cout << endl;
}
cout << "���������� �� �����������\n";
for (int i=0;i<n;i++)
{
    for (int j=i+1;j<n;j++)
    {
        if((x[i].year>x[j].year) | (x[i].month>x[j].month && x[i].year==x[j].year) | (x[i].day>x[j].day && x[i].month==x[j].month && x[i].year==x[j].year))
        {
            swap(x[i],x[j]);
        }
    }
}
cout << "����� ��������������� ������.\n__________________________________\n";
for (int i=0; i<n;i++)
{
    cout << "���� �" << i+1 << endl;
    display(x[i]);
    cout << endl;
}

    return 0;
}
