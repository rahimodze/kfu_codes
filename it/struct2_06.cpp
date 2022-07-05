#include <iostream>
#include <string>
using namespace std;
struct book
{
    string author_name;
    string name;
    int year;
};
int main()
{
int n = 12;
book x[n];
for (int i=0;i<n;i++)
{
    x[i].author_name = rand();
    x[i].name = rand();
    x[i].year = rand();
}
string key;
cout << "Enter keyword:"; cin >> key;
for (int i=0;i<n;i++)
{
    if((x[i].name.find(key)!=-1))
    {
        cout << x[i].name;
    cout << endl;
}
}
    return 0;
}
