// ����� �� ���������� ������� ������� ����� �����.cpp : ���� ���� �������� ������� "main". ����� ���������� � ������������� ���������� ���������.
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
    double magnetization() const // ���������� ���������� ���������������
    {
        double m = 0;
        for (int i = 0; i < s.size(); i++)
        {
           m += s[i];
        }
        return  m / s.size();
    }
    double energy() const // ������� �������������� ����
    {
        double res = -J * (s[0] + s[s.size()-1]);
        for (int i = 0; i < s.size() - 1; i++)
        {
            res += -J * (s[i] * s[i + 1]);
        }
        return res;
    }

    void relax(int tau) // ����������� ��������� ����� ��� ��� ������ � ������ ���� ������, ��� ������ � ������ ���� ���� �������� ������������ ���������
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
// ���� ���������� ������� ��������������� �� �����������
    }

    std::cout << "Hello World!\n";
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
