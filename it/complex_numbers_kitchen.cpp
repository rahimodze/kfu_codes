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
        std::cout << "����������� �����:" << z.real << '+' << z.imaginary << 'i' << std::endl;
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
    cout << "����� ���������� � ������� �� ������ � ������������ �������!" << endl;
    Menu:
    system("cls");
    setlocale(LC_ALL,"rus");
    cout << "����:" << endl;
    cout << "1. ������������\n2. ���������\n3. ������������\n4. �������\n5. ����������� ������\n6. ����� ������������\n0. ���������� ������\n" ;
    cout << "������� �������� ������� (����� ����):";
    input:
    cin >> n;
    switch(n)
    {
        case 1:
        {
            cout << "�� ������� ������������." << endl;
            cout << "���� ������\n";
            mnim c1;
            mnim c2;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c1.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c1.imaginary;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c2.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 + c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 2:
            {
             cout << "�� ������� ���������." << endl;
            cout << "���� ������\n";
            mnim c1;
            mnim c2;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c1.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c1.imaginary;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c2.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 - c2;
            display(c3);
            system("pause");
            goto Menu;
            }
        case 3:
        {
            cout << "�� ������� ������������." << endl;
            cout << "���� ������\n";
            mnim c1;
            mnim c2;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c1.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c1.imaginary;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c2.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 * c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 4:
        {
            cout << "�� ������� �������." << endl;
            cout << "���� ������\n";
            mnim c1;
            mnim c2;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c1.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c1.imaginary;
            cout << "������� ������������ ����������� ������� �����:"; cin >> c2.real;
            cout << "������� ������ ����������� ������� �����:"; cin >> c2.imaginary;
            mnim c3;
            c3 = c1 / c2;
            display(c3);
            system("pause");
            goto Menu;
        }
        case 5:
            {
            cout << "�� ������� ���������� ������." << endl;
            cout << "���� ������\n";
            mnim c1;
            cout << "������� ������������ �����������:"; cin >> c1.real;
            cout << "������� ������ �����������:"; cin >> c1.imaginary;
            cout << "������ ����� �����:" << dlina(c1) << endl;
            system("pause");
            goto Menu;
            }
        case 6:
            {
            cout << "�� ������� ����� ������������." << endl;
            cout << "���� ������\n";
            mnim c1;
            cout << "������� ������������ �����������:"; cin >> c1.real;
            cout << "������� ������ �����������:"; cin >> c1.imaginary;
            mnim c3;
            c3 = sopr(c1);
            cout << "����������� ������� ����� ��������" << endl;
            display(c3);
            system("pause");
            goto Menu;
            }
        default:
            {
                cout << "������. ������������ ����. ������� ���������� ����� ����:";
                goto input;
            }
            case 0:
                {
                    cout << "������ ��������� ���������. ������� �� �����������!";
                    break;
                }
    }
return 0;
}
