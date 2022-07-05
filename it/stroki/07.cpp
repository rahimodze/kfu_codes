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
    std::getline(cin, x, '\n');
    cout << "Проверка палиндромного признака***" << endl;
    string y(x.rbegin(), x.rend());
    cout << "Реверс - " << y << endl;
    if (x.compare(y) !=0)
    {
        cout << "Не палиндром";
    }
    else
    {
        cout << "Хорошее слово, палиндромное...";
    }
    return 0;
}
