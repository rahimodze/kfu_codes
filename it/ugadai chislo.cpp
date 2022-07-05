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
cout << "Угадай число." << endl;
cout << "-----------------\n";
cout << "Меню\n";
cout << " 1 Одиночная игра\n";
cout << " 2 Hotseat\n";
cout << " 3 Правила\n";
cout << " 4 Выход\n";
int s = 0;
cout << "ВЫБЕРИТЕ ДЕЙСТВИЕ:";cin >> s;
switch (s)
{
case 1:
    {
        int q = 0;
        cout << "Введите верхнюю границу диапазона:";cin >>q;
        unsigned int star = 1 + rand()%q;
        cout << "Число сгенерировано. Удачи!\n";
        for (int i=1; i<=5; i++)
        {
            cout << "Попытка №" << i << "." << endl;
            int guess = 0;
            cout << "Введите число:";cin >> guess;
            if(guess!=star)
            {
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "числа различаются меньше чем на 10. вы очень близко\n";
                        continue;
                    }
                if(range<100)
                    {
                        cout << "числа различаются меньше чем на 100" << endl;
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "числа различаются меньше чем на 1000" << endl;
                        continue;
                    }
                }
            else
            {
                cout << "в точку. число угадано." << endl;
                system("pause");
                break;
            }
        }
        cout << "Число свободных попыток подошло к концу. Игра окончена. Вы проиграли. :(\n";
        system("pause");
        goto menu;
        break;
    }
case 2:
    {
        int q1=0;
        cout << "Первый игрок.\nВведите верхнюю границу диапазона:";cin >>q1;
        int q2=0;
        cout << "Второй игрок.\nВведите верхнюю границу диапазона:";cin >>q2;
        unsigned int star = 0 + rand()%10;
        if((star%2==1))
        {
            cout << "Сыграла граница первого игрока. Число сгенерировано. Удачи!" << endl;
            unsigned int star = 1 + rand()%q1;
        }
        else
        {
            cout << "Сыграла граница второго игрока. Число сгенерировано. Удачи!" << endl;
            unsigned int star = 1 + rand()%q2;
        }
        system("pause");
        for (int i=1; i<=10; i++)
        {
            system("cls");
            setlocale(0,"");
            if(i%2==1)
            {
            cout << "Игрок 1. Попытка №" << trunc(i/2+1) << "." << endl;
            int guess = 0;
            cout << "Введите число:";cin >> guess;
            if(guess!=star)
            {
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "числа различаются меньше чем на 10. вы очень близко\n";
                        system("pause");
                        continue;
                    }
                if(range<100)
                    {
                        cout << "числа различаются меньше чем на 100" << endl;
                        system("pause");
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "числа различаются меньше чем на 1000" << endl;
                        system("pause");
                        continue;
                    }
                }
            else
            {
                cout << "в точку. число угадано." << endl;
                system("pause");
                break;
            }
        }
        if (i%2==0)
        {
            cout << "Игрок 2. Попытка №" << trunc(i/2) << "." << endl;
            int guess = 0;
            cout << "Введите число:";cin >> guess;
            if(guess!=star)
            {
                if(i==10)
                {
                    cout << "Число свободных попыток подошло к концу. Игра окончена. Вы проиграли. :(\n";
                    system("pause");
                    goto menu;
                    break;
                }
                int range = fabs(star-guess);
                if (range<10)
                    {
                        cout << "числа различаются меньше чем на 10. вы очень близко\n";
                        system("pause");
                        continue;
                    }
                if(range<100)
                    {
                        cout << "числа различаются меньше чем на 100" << endl;
                        system("pause");
                        continue;
                    }
                if(range<1000)
                    {
                        cout << "числа различаются меньше чем на 1000" << endl;
                        system("pause");
                        continue;
                    }
                }
            else
            {
                cout << "в точку. число угадано." << endl;
                system("pause");
                break;
            }
        }
    }
            }

case 3:
    {
        cout << "Игроку необходимо точно угадать натуральное число, сгенерированное компьютером." << endl;
        cout << "При выборе одиночной игры пользователь задаёт верхнюю границу генерируемого диапазона." << endl;
        cout << "При выборе режима hotseat верхняя граница выбирается случайно из чисел, предложенных игроками." << endl;
        cout << "Число попыток ограничено, однако в случае неверного ввода игроку сообщается,\nнасколько различаются введенное и загаданное числа." << endl;
        system("pause");
        goto menu;
    }
case 4:
    goto end;
}
goto menu;
end:
cout << "Работа программы завершена.";
return 0;
}
