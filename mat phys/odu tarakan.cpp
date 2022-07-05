// odu.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

std::vector<double> dynamical_system(const std::vector<double>& x, double t)
{
    std::vector<double> f(x.size());
    double u = 5;
    double l = 17;
    double v0=50;
    return { u + x[0] * v0 / (l + v0 * t)};
}


template <class f, class Observer>
std::vector<double> odu(std::vector<double>& X0, const f& F, double T, double T0, double dt, Observer spy)
{
    std::vector<double> X = X0;
    double t = T0;
    int n = (T - T0) / dt;
    dt = (T - T0) / (double)n;
    while (t < T)
    {
        for (int j = 0; j < X.size(); j++)
        {
            X[j] += F(X, t)[j] * dt;
        }
        spy(X, t);
        t += dt;
    }
    return X;
}

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
    std::vector<double> Y0 = {17};
    double tau = 10000;
    double dt = 0.5;
    std::ofstream out("data.txt");
    odu(Y0, dynamical_system, tau, 0.0000, dt, [&](std::vector<double> & X, double t)
        {
    out << t << "\t" << X[0] << "\n";
        }
        );

}
