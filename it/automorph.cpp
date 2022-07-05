#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
int n=0;
int k=0;
setlocale(LC_ALL,"rus");
cout << "Введите число:";
cin >> n;
string base = to_string(n);
int rectangle = n*n;
string kvadrat = to_string(rectangle);
std::reverse(kvadrat.begin(), kvadrat.end());
std::reverse(base.begin(), base.end());
for (int i = 0; i < base.length(); i++)
{
if (base[i]!=kvadrat[i])
{
    cout << "Не автоморф" << endl;
    k++;
    break;
}
}
if(k==0)
{
    cout << "Автоморф" << endl;
}
    return 0;
}
