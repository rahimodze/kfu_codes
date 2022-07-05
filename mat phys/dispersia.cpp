// odu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>

//double odu(, )

double sdt_dev(std::vector<double>& b)
{
    double av = 0.0000;
    double sqav = 0.0000;
    int i = 0;
    while (i < b.size())
    {
        av += b[i];
        sqav += b[i] * b[i];
        i++;
    }
    av = av / b.size();
    av = av * av;
    sqav = sqav / b.size();
    return sqrt(av);
}

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dist(0, 10);
    std::vector<double> v(10);
    v[0] = 2.718281828459045;
    int i = 0;
    while(i < v.size())
    {
        v[i] = dist(gen);
        std::cout << "v[" << i << "] == " << v[i] << std::endl;
            i++;
    }
    std::cout << sdt_dev(v) << std::endl;
    std::cout << "Hello World!\n";
}