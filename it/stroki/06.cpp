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
    cout << "������� ������:";
    std::getline(cin,x);
    cout << "��������***" << endl;
    string y;
    y = x;
    reverse(y.begin(), y.end());
    cout << "�������� ������ -> " << y << endl;
    return 0;
}
