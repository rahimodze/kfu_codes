#include <iostream>
#include <cmath>
#include <windows.h>
#include <cstdlib>
using namespace std;
struct mnim
{
double real;
double imaginary;
};
void display(mnim z)
{
        setlocale(LC_ALL,"rus");
        std::cout << "Комплексное число:" << z.real << '+' << z.imaginary << 'i' << std::endl;
}
mnim sopr(mnim z)
{
    return mnim{z.real,z.imaginary *(-1)};
}
double dlina(mnim z)
{
    return sqrt(pow(z.real,2)+ pow(z.imaginary,2));
}
mnim operator + (mnim c1, mnim c2)
{
    return mnim{c1.real + c2.real, c1.imaginary + c2.imaginary};
}
mnim operator - (mnim c1, mnim c2)
{
    return mnim{c1.real - c2.real, c1.imaginary - c2.imaginary};
}
mnim operator * (mnim c1, mnim c2)
{
    return mnim{c1.real * c2.real - c1.imaginary*c2.imaginary, c1.imaginary*c2.real + c2.imaginary*c1.real};
}
mnim operator / (mnim c1, mnim c2)
{
    return mnim{(c1.real * c2.real + c1.imaginary*c2.imaginary)/dlina(c2), (c1.imaginary*c2.real - c2.imaginary*c1.real)/dlina(c2)};
}
int main()
{
    setlocale(LC_ALL,"rus");
    int n = 99;
    cout << "Добро пожаловать в комбайн по работе с комплексными числами!" << endl;
    Menu:
    system("cls");
    setlocale(LC_ALL,"rus");
    cout << "Меню:" << endl;
    cout << "1. Суммирование\n2. Вычитание\n3. Перемножение\n4. Деление\n5. Возвращение модуля\n6. Поиск сопряженного\n0. Завершение работы\n" ;
    cout << "Введите желаемую функцию (пункт меню):";
    input:
    cin >> n;
    switch(n)
    {
        case 1:
        {
            cout << "Вы выбрали суммирование." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            mnim c2;
            cout << "Введите вещественную компноненту первого числа:"; cin >> c1.real;
            cout << "Введите мнимую компноненту первого числа:"; cin >> c1.imaginary;
            cout << "Введите вещественную компноненту второго числа:"; cin >> c2.real;
            cout << "Введите мнимую компноненту второго числа:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 + c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 2:
            {
             cout << "Вы выбрали вычитание." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            mnim c2;
            cout << "Введите вещественную компноненту первого числа:"; cin >> c1.real;
            cout << "Введите мнимую компноненту первого числа:"; cin >> c1.imaginary;
            cout << "Введите вещественную компноненту второго числа:"; cin >> c2.real;
            cout << "Введите мнимую компноненту второго числа:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 - c2;
            display(c3);
            system("pause");
            goto Menu;
            }
        case 3:
        {
            cout << "Вы выбрали произведение." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            mnim c2;
            cout << "Введите вещественную компноненту первого числа:"; cin >> c1.real;
            cout << "Введите мнимую компноненту первого числа:"; cin >> c1.imaginary;
            cout << "Введите вещественную компноненту второго числа:"; cin >> c2.real;
            cout << "Введите мнимую компноненту второго числа:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 * c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 4:
        {
            cout << "Вы выбрали деление." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            mnim c2;
            cout << "Введите вещественную компноненту первого числа:"; cin >> c1.real;
            cout << "Введите мнимую компноненту первого числа:"; cin >> c1.imaginary;
            cout << "Введите вещественную компноненту второго числа:"; cin >> c2.real;
            cout << "Введите мнимую компноненту второго числа:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 / c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 5:
            {
            cout << "Вы выбрали нахождение модуля." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            cout << "Введите вещественную компноненту:"; cin >> c1.real;
            cout << "Введите мнимую компноненту:"; cin >> c1.imaginary;
            cout << "Модуль числа равен:" << dlina(c1) << endl;
            system("pause");
            goto Menu;
            }
        case 6:
            {
            cout << "Вы выбрали поиск сопряженного." << endl;
            cout << "Ввод данных\n";
            mnim c1;
            cout << "Введите вещественную компноненту:"; cin >> c1.real;
            cout << "Введите мнимую компноненту:"; cin >> c1.imaginary;
            mnim c3;
            c3 = sopr(c1);
            cout << "Сопряженным данного числа является" << endl;
            display(c3);
            system("pause");
            goto Menu;
            }
        default:
            {
                cout << "Ошибка. Некорректный ввод. Введите корректный пункт меню:";
                goto input;
            }
            case 0:
                {
                    cout << "Работа программы завершена. Спасибо за пользование!";
                    break;
                }
    }
return 0;
}
