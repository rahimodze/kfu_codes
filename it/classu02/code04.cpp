#include <iostream>
#include <cmath>
using namespace std;
class time
{
public:
    int hour;
    int minute;
    int second;
time()
{
cout << "enter hour:";cin >> hour;
if((hour<0) | (hour>23))
    {
     cout << "incorrect input.\n";
        hour = 1;
        gethour();
    }
    cout << "enter minutes:";cin >> minute;
    if((minute<0) | (minute>59) )
    {
     cout << "incorrect input.\n";
        minute = 1;
        getminute();
    }
    cout << "enter seconds:";cin >> second;
    if((second<0) | (second>59))
    {
     cout << "incorrect input.\n";
        second = 1;
        getseconds();
    }
}

void gethour()
{
    cout << "enter hour:";cin >> hour;
    if((hour<0) | (hour>23) )
    {
     cout << "incorrect input.\n";
        hour = 1;
        gethour();
    }
}
void getminute()
{
    cout << "enter minutes:";cin >> minute;
    if((minute<0) | (minute>59) )
    {
     cout << "incorrect input.\n";
        minute = 1;
        getminute();
    }
}
void getseconds()
{
    cout << "enter seconds:";cin >> second;
    if((second<0) | (second>59))
    {
     cout << "incorrect input.\n";
        second = 1;
        getseconds();
    }
}
void showEU()
{
    if (second%10==1)
    {
        cout << "�����: " << hour << " ����� " << minute << " ����� " << second << " �������." << endl;
    }
    if ((second%10==2) | (second%10==3) | (second%10==4))
    {
        cout << "�����: " << hour << " ����� " << minute << " ����� " << second << " �������." << endl;
    }
    if(second%10>4)
    {
            cout << "�����: " << hour << " ����� " << minute << " ����� " << second << " ������." << endl;
    }
}
void showUS()
{
    if(hour>12)
    {
            if (second%10==1)
    {
        cout << "�����: " << abs(hour-12) << " pm " << minute << " ����� " << second << " �������." << endl;
    }
    if ((second%10==2) | (second%10==3) | (second%10==4))
    {
        cout << "�����: " << abs(hour-12) << " pm " << minute << " ����� " << second << " �������." << endl;
    }
    if(second%10>4)
    {
            cout << "�����: " << abs(hour-12) << " pm " << minute << " ����� " << second << " ������." << endl;
    }
    }
    if(hour<=12)
    {
    if (second%10==1)
    {
        cout << "�����: " << abs(hour-12) << " am " << minute << " ����� " << second << " �������." << endl;
    }
    if ((second%10==2) | (second%10==3) | (second%10==4))
    {
        cout << "�����: " << abs(hour-12) << " am " << minute << " ����� " << second << " �������." << endl;
    }
    if(second%10>4)
    {
    cout << "�����: " << abs(hour-12) << " am " << minute << " ����� " << second << " ������." << endl;
    }
    }
}

};
int main()
{
    setlocale(LC_ALL,"");
    cout << "clock via classes" << endl;
    time a;
    char k;
    input:
    cout << "in which format do you wanna see time? EU or US? e/u:";cin >> k;
    if(k=='e')
        a.showEU();
    if(k=='u')
        a.showUS();
    if((k!='e') && (k!='u'))
    {
        cout << "funny. -_- enter properly." << endl;
        goto input;
    }
    return 0;
}
