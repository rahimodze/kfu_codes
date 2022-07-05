#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
setlocale(LC_ALL,"rus");
unsigned int k = 0;
unsigned int sum = 0;
cout << "Вывод квадратов чисел, номер которых равен сумме номера нечетных" << endl;
cout << "Введите верхнюю границу желаемого диапазона:";
cin >> k;
for (unsigned int i=1; i<=k;i++)
{
    sum +=(2*i-1);
    cout << "Сумма нечетных = " << sum << endl;
        if(sum == pow(i,2))
        {
            cout << "Число " << i << " отвечает условиям. Его квадрат " << pow(i,2) << endl;
        }
}
    return 0;
}
