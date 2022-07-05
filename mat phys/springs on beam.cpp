// ������������� �� ����� ������.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
//

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <fstream>

std::vector<double> dynamical_system(const std::vector<double>& x, double)
{
    std::vector<double> f(x.size());
    double k = 1; // ������� ������ �� ��������
    double m = 1;
    double M = 4;
    double mu = 1;
    f = { -k * x[3], -k * x[4], k * x[3] + k * x[4] - mu*x[2]/M, x[0] / m - x[2] / M, x[1] / m - x[2] / M, x[2] / M};
    return f;
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
    std::vector<double> Y0 = {0, 0, 0, 0.05, 0, 0 }; // p1 p2 px q1 q2 x
    double tau = 150.0000;
    double dt = 0.01;
    std::ofstream out("data.txt");
    odu(Y0, dynamical_system, tau, 0.0000, dt, [&](std::vector<double>& X, double t)
        {
            //out << t << "\t" << X[3] << "\t" << X[4] << "\t" << X[5] << "\t" << X[0] << "\t" << X[1] << "\t" << X[2] << "\n";
            //out << t << "\t" << X[3] << "\t" << X[4] << "\t" << X[5] << "\n";
            out << t << "\t" << (pow(X[3],2)/2 + pow(X[4], 2)/2 + pow(X[0], 2)/2 + pow(X[1], 2)/2 + pow(X[2], 2)/2) << "\n";
        });

}

// ������ ���������: CTRL+F5 ��� ���� "�������" > "������ ��� �������"
// ������� ���������: F5 ��� ���� "�������" > "��������� �������"

// ������ �� ������ ������ 
//   1. � ���� ������������ ������� ����� ��������� ����� � ��������� ���.
//   2. � ���� Team Explorer ����� ������������ � ������� ���������� ��������.
//   3. � ���� "�������� ������" ����� ������������� �������� ������ ������ � ������ ���������.
//   4. � ���� "������ ������" ����� ������������� ������.
//   5. ��������������� �������� ������ ���� "������" > "�������� ����� �������", ����� ������� ����� ����, ��� "������" > "�������� ������������ �������", ����� �������� � ������ ������������ ����� ����.
//   6. ����� ����� ������� ���� ������ �����, �������� ������ ���� "����" > "�������" > "������" � �������� SLN-����.
