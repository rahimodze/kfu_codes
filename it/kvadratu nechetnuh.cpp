#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
setlocale(LC_ALL,"rus");
unsigned int k = 0;
unsigned int sum = 0;
cout << "����� ��������� �����, ����� ������� ����� ����� ������ ��������" << endl;
cout << "������� ������� ������� ��������� ���������:";
cin >> k;
for (unsigned int i=1; i<=k;i++)
{
    sum +=(2*i-1);
    cout << "����� �������� = " << sum << endl;
        if(sum == pow(i,2))
        {
            cout << "����� " << i << " �������� ��������. ��� ������� " << pow(i,2) << endl;
        }
}
    return 0;
}
