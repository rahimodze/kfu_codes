#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
cout << "Сортировщик" << endl;
string x;
ifstream c("file.txt");
getline(c,x);
c.close();
int words = 1;
for (int i=0; i<x.length(); i++)
{
    if(x[i]==' ')
        words++;
}
cout << "Начальная строка\n" << x << endl;
string y[words];
c.open("file.txt",ios::app);
for (int i=0; i<words; i++)
{
    c >> y[i];
}
c.close();
sort(y[0],y[words]);
ofstream o("beb.txt");
for (int i=0; i<words; i++)
{
    o << y[i] << "\t";
}
o.close();
    return 0;
}
