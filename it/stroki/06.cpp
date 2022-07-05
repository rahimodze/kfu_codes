#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    setlocale(0, "russian");
    string x;
    cout << "Введите строку:";
    std::getline(cin,x);
    cout << "Отражаем***" << endl;
    string y;
    y = x;
    reverse(y.begin(), y.end());
    cout << "Конечная строка -> " << y << endl;
    return 0;
}
