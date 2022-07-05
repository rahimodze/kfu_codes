// спины на одномерной цепочки методом монте карло.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
#include <iomanip>
#include <vector>
#include <cmath>
#include <fstream>
class spinner
{
private:
    int l;
    double T;
    double J;
    std::vector<int> s;
    std::mt19937 m_gen;

public:
    spinner(int a = 100, double t = 273, double j = 1)
        : l(a), T(t), J(j), s(a, 1), m_gen(std::random_device()())
    {

    }
    double magnetization() const // мгновенное вычисление намагниченности
    {
        double m = 0;
        for (int i = 0; i < s.size(); i++)
        {
           m += s[i];
        }
        return  m / s.size();
    }
    double energy() const // энергия взаимодействия цепи
    {
        double res = -J * (s[0] + s[s.size()-1]);
        for (int i = 0; i < s.size() - 1; i++)
        {
            res += -J * (s[i] * s[i + 1]);
        }
        return res;
    }

    void relax(int tau) // виртуальный переворот спина тау раз дельте е меньше нуля гарант, при дельта е больше нуля надо смотреть распределние больцмана
    {
        for (int j = 0; j < tau; j++)
        {
            for (int i = 0; i < s.size(); i++)
            {
                std::uniform_real_distribution<double> xi(0.0, 1.0);
                double diff = 0;
                if (i == 0)
                {
                    diff = 2*J*s[i]*(1+s[i+1]);
                }
                if (i == s.size()-1)
                {
                    diff = 2*J*s[i]*(1+s[i-1]);
                }
                if ((i != 0) && (i != (s.size()-1)))
                {
                    diff = 2*J*s[i]*(s[i-1] + s[i+1]);
                }
                if (diff < 0)
                {
                    s[i] = -1 * s[i];
                }
                else
                {
                    if (xi(m_gen) < exp(-diff / T))
                    {
                        s[i] = -s[i];
                    }
                }
            }
        }
    }
};

int main()
{
    int length; double temp; double moment; int time;
    std::cout << "enter chain length:"; std::cin >> length;
    std::cout << "enter temperature:"; std::cin >> temp;
    std::cout << "enter magnetic coefficient:"; std::cin >> moment;
    std::cout << "enter time of observation:"; std::cin >> time;
    spinner test(length, temp, moment);
    std::cout << "Initial magnitization:" << test.magnetization() << std::endl;
    std::ofstream out("data.txt");
    for (int i = 0; i < time; i++)
    {
        test.relax(i);
        out << (i) << "\t" << std::setprecision(9) << test.magnetization() << "\t" << test.energy() << "\n";
// дома посмотреть среднюю намагниченность от температуры
    }

    std::cout << "Hello World!\n";
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
