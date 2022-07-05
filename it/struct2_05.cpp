#include <iostream>
#include <time.h>
using namespace std;
struct room
{
    int day;
    int para;
    int number;
    string discipline;
    bool free;
};
int main()
{
srand(time(0));
int n = 9;
room x[n];
int number = 0;
for (int i=0;i<n;i++)
{
    x[i].day = 1 + rand()%5;
    x[i].para = 1 + rand()%5;
    x[i].number = 1 + rand()%1000;
    x[i].free = rand()%2;

}
    cout << "Available rooms" << endl;
    for (int i=0; i<n; i++)
    {
        cout << x[i].number;
        cout << endl;
    }
cout << "Enter needed room:"; cin >> number;
for (int i=0; i<n;i++)
{
    if(x[i].number == number && x[i].free == 1)
        cout << "It's free at day num " << x[i].day << " during lesson num " << x[i].para << endl;
}
    return 0;
}
