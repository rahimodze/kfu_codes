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
    std::getline(cin, x, '\n');
    cout << "�������� ������������� ��������***" << endl;
    string y(x.rbegin(), x.rend());
    cout << "������ - " << y << endl;
    if (x.compare(y) !=0)
    {
        cout << "�� ���������";
    }
    else
    {
        cout << "������� �����, ������������...";
    }
    return 0;
}
