#include <iostream>

using namespace std;
class date
{
public:
int year;
int month;
int day;
date()
{
getyear();
getmonth();
getday();
}
void getyear()
{
    cout << "enter year:";cin >> year;
    if(year<=0)
    {
        cout << "incorrect input. try again.\n";
        year=1;
        getyear();
    }
}
void getmonth()
{
    cout << "enter month:";cin >> month;
    if((month<=0) | (month>12))
    {
        cout << "incorrect input. try again.\n";
        month=1;
        getmonth();
    }
}
void getday()
{
    cout << "enter day:";cin >> day;
    if((day<=0) | (day>31))
    {
        cout << "incorrect input. try again.\n";
        day=1;
        getday();
    }
}
void wordout()
{
    cout << "Day:" << day << endl;
    cout << "Month:" << month << endl;
    cout << "Year:" << year << endl;
}
void numbout()
{
    cout << day << "." << month << "." << year << endl;
}
};

int main()
{
    cout << "calendar via classes" << endl;
    date a;
    char c;
    input:
    cout << "in which form do you wanna see date? numbers or words? n/w:";cin >> c;
    if(c=='n')
        a.numbout();
    if(c=='w')
        a.wordout();
    if((c!='n') && (c!='w'))
    {
        cout << "error. incorrect input. try again." << endl;
        goto input;
    }
    return 0;
}
