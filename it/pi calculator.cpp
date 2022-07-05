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
cout << "Введите желаемую точность:";
cin >> eps;
cout << endl;
int i = 0;
cout << "Вычисление***" << endl;
while (fabs(product-pi)/pi>eps)
       {
            product += 4*(2/(16*pow(i,2)+16*i+3));
            cout << product << endl;
            i++;
       }
cout << "Готово. Число пи примерно равно =" << product << endl;
system("pause");
    return 0;
}
