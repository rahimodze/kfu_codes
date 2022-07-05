// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
using namespace std;
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <stdexcept>
#include <iomanip>
#define M_PI 3.14159265358979323846

template <class func>
double simpson(double a, double b, int n, func d)
{
    double h = fabs(b - a) / (2 * n);
    double sum1 = d(a) + d(b);
    for (int i = 1; i < 2 * n; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += 2 * d(a + i * h);
            continue;
        }
        sum1 += 4 * d(a + i * h);
    }
    return sum1 * h / 3;
}
double gauss(double x)
{
    return exp(-x * x);
}
double fourier(double x, double l, double t, int n)
{
    double a0 = (1/l)*simpson(-l / 2, l / 2, 500, [&](double y)
        {
            return exp(-y * y);
        });
    cout << a0 << '\t';
    for (double i = 1; i <= n; i++)
    {
        double An = (2 / l) * simpson(-l/2, l / 2, 500, [&](double y)
            {
               return exp(-y * y) * cos (2 * M_PI * i * y / l );
            });
        cout << An << '\t';
        a0 += An * exp(-(2 * M_PI * i / l)* (2 * M_PI * i / l) * t) * cos(2 * M_PI * i * x / l);
        cout << a0 << endl;
    }
    return a0;
}

int main()
{
    std::cout << "Hello World!\n";
    double x = -M_PI / 2;
    double X = M_PI / 2;
    //    cout << "A0 == " << A0 << endl;
    std::ofstream out("data.txt");
    while (x < X)
    {
        double dummy = fourier(x, 4, 1, 100);
        out << x << "\t" << std::setprecision(10) << dummy << endl;
        x += 0.01;
    }
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
