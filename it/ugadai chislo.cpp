#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <cmath>
// by Rdze

using namespace std;
int main()
{
srand(time(0));
menu:
system("cls");
setlocale(0,"");
cout << "-----------------\n";
cout << "������ �����." << endl;
cout << "-----------------\n";
cout << "����\n";
cout << " 1 ��������� ����\n";
cout << " 2 Hotseat\n";
cout << " 3 �������\n";
cout << " 4 �����\n";
int s = 0;
cout << "�������� ��������:";cin >> s;
switch (s)
{
case 1:
    {
        int q = 0;
        cout << "������� ������� ������� ���������:";cin >>q;
        unsigned int star = 1 + rand()%q;
        cout << "����� �������������. �����!\n";
        for (int i=1; i<=5; i++)
        {
            cout << "������� �" << i << "." << endl;
            int guess = 0;
            cout << "������� �����:";cin >> guess;
            if(guess!=star)
            {
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "����� ����������� ������ ��� �� 10. �� ����� ������\n";
                        continue;
                    }
                if(range<100)
                    {
                        cout << "����� ����������� ������ ��� �� 100" << endl;
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "����� ����������� ������ ��� �� 1000" << endl;
                        continue;
                    }
                }
            else
            {
                cout << "� �����. ����� �������." << endl;
                system("pause");
                break;
            }
        }
        cout << "����� ��������� ������� ������� � �����. ���� ��������. �� ���������. :(\n";
        system("pause");
        goto menu;
        break;
    }
case 2:
    {
        int q1=0;
        cout << "������ �����.\n������� ������� ������� ���������:";cin >>q1;
        int q2=0;
        cout << "������ �����.\n������� ������� ������� ���������:";cin >>q2;
        unsigned int star = 0 + rand()%10;
        if((star%2==1))
        {
            cout << "������� ������� ������� ������. ����� �������������. �����!" << endl;
            unsigned int star = 1 + rand()%q1;
        }
        else
        {
            cout << "������� ������� ������� ������. ����� �������������. �����!" << endl;
            unsigned int star = 1 + rand()%q2;
        }
        system("pause");
        for (int i=1; i<=10; i++)
        {
            system("cls");
            setlocale(0,"");
            if(i%2==1)
            {
            cout << "����� 1. ������� �" << trunc(i/2+1) << "." << endl;
            int guess = 0;
            cout << "������� �����:";cin >> guess;
            if(guess!=star)
            {
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "����� ����������� ������ ��� �� 10. �� ����� ������\n";
                        system("pause");
                        continue;
                    }
                if(range<100)
                    {
                        cout << "����� ����������� ������ ��� �� 100" << endl;
                        system("pause");
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "����� ����������� ������ ��� �� 1000" << endl;
                        system("pause");
                        continue;
                    }
                }
            else
            {
                cout << "� �����. ����� �������." << endl;
                system("pause");
                break;
            }
        }
        if (i%2==0)
        {
            cout << "����� 2. ������� �" << trunc(i/2) << "." << endl;
            int guess = 0;
            cout << "������� �����:";cin >> guess;
            if(guess!=star)
            {
                if(i==10)
                {
                    cout << "����� ��������� ������� ������� � �����. ���� ��������. �� ���������. :(\n";
                    system("pause");
                    goto menu;
                    break;
                }
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "����� ����������� ������ ��� �� 10. �� ����� ������\n";
                        system("pause");
                        continue;
                    }
                if(range<100)
                    {
                        cout << "����� ����������� ������ ��� �� 100" << endl;
                        system("pause");
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "����� ����������� ������ ��� �� 1000" << endl;
                        system("pause");
                        continue;
                    }
                }
            else
            {
                cout << "� �����. ����� �������." << endl;
                system("pause");
                break;
            }
        }
    }
            }

case 3:
    {
        cout << "������ ���������� ����� ������� ����������� �����, ��������������� �����������." << endl;
        cout << "��� ������ ��������� ���� ������������ ����� ������� ������� ������������� ���������." << endl;
        cout << "��� ������ ������ hotseat ������� ������� ���������� �������� �� �����, ������������ ��������." << endl;
        cout << "����� ������� ����������, ������ � ������ ��������� ����� ������ ����������,\n��������� ����������� ��������� � ���������� �����." << endl;
        system("pause");
        goto menu;
    }
case 4:
    goto end;
}
goto menu;
end:
cout << "������ ��������� ���������.";
return 0;
}
