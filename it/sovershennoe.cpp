#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
setlocale(LC_ALL,"rus");
cout << "�������� �������� ������������ �����" << endl;
int n=0;
cout << "������� �����:";
cin >> n;
int s=0;
for (int i=1; i<n; i++)
    {
    if(n%i==0)
    s+=i;
    if (s==n)
    {
        cout << "����� ����������" << endl;
        break;
    }
    if(s>n)
    {
        cout << "����� ������������" << endl;
        break;
    }
    if((i>n/2) && (s!=n))
        {
        cout << "����� ������������" << endl;
        break;
        }
    }
    return 0;
}
