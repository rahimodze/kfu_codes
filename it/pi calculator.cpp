#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

int main()
{
float const pi = 3.141592;
float product = 0;
int eps = 0;
setlocale(LC_ALL, "rus");
cout << "������� �������� ��������:";
cin >> eps;
cout << endl;
int i = 0;
cout << "����������***" << endl;
while (fabs(product-pi)/pi>eps)
       {
            product += 4*(2/(16*pow(i,2)+16*i+3));
            cout << product << endl;
            i++;
       }
cout << "������. ����� �� �������� ����� =" << product << endl;
system("pause");
    return 0;
}
