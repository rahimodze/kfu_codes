#include <iostream>
#include <string>
using namespace std;
class train
{
public:
string destination;
int number;
string time;
void get_destination()
{
cout << "enter destination:";getline(cin,destination);
}
void get_number()
{
cout << "enter train number:";cin >> number; cin.ignore();
}
void get_time()
{
cout << "enter time of leaving:";getline(cin,time);
}
};
void swap(train& a, train& b)
{
    train temp;
    temp.destination=a.destination;
    temp.number=a.number;
    temp.time=a.time;
    a.destination=b.destination;
    a.number=b.number;
    a.time=b.time;
    b.destination=temp.destination;
    b.number=temp.number;
    b.time=temp.time;
}
int main()
{
int n = 5;
train x[n];
for (int i=0; i<n;i++)
{
    x[i].get_destination();
    x[i].get_number();
    x[i].get_time();
}
cout << "sortin'\n";
for (int i=0;i<n;i++)
{
    for (int j=i+1;j<n;j++)
    {
        if(x[i].destination>x[j].destination)
            {
                swap(x[i],x[j]);
                cout << "swapped by destination.\n";
            }
    }
}
for (int i=0;i<n;i++)
{
    for (int j=0; j<n; j++)
    {
        if((x[i].destination==x[j].destination) && (x[i].time>x[j].time))
        {
             swap(x[i],x[j]);
             cout << "swapped by times\n";
        }
    }
}
int k=0;
cout << "need to output all datasheet? (0 for no, any number for y)";cin >> k;
if (k!=0)
{
cout << "outputting sorted data***" << endl;
cout.width(20); cout << "number\t";cout.width(20); cout << "destination\t";cout.width(20); cout << "leaving time\t" << endl;
for (int i=0;i<n;i++)
{
    cout.width(20);
    cout << x[i].number;
    cout.width(20);
    cout << x[i].destination;
    cout.width(20);
    cout << x[i].time << endl;
}
}
int numb;
cout << "enter needed train number:";cin >> numb;
for (int i=0;i<n;i++)
{
    if(numb==x[i].number)
    {
    cout.width(20);
    cout << x[i].number;
    cout.width(20);
    cout << x[i].destination;
    cout.width(20);
    cout << x[i].time << endl;
    }
}
return 0;
}

