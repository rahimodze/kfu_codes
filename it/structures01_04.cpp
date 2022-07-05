#include <iostream>
#include <cmath>
#include <string.h>
#include <algorithm>
#include <vector>
#include <windows.h>
using namespace std;

struct marks
{
    int physics;
    int math;
    int chemistry;
};
struct student
{
    string name;
    string group;
    float average;
    marks points;
};
int main()
{
    setlocale(LC_ALL,"rus");
    const int numb = 10;
    student stud1[numb];
    for (int i = 0; i<numb; i++)
    {
        cout << "Введите фамилию студента:"; cin >> stud1[i].name;
        cout << "Введите номер группы:"; cin >> stud1[i].group;
        cout << "Введите оценки \n";
        cout << "Физика:"; cin >> stud1[i].points.physics;
        cout << "Матанализ:"; cin >> stud1[i].points.math;
        cout << "Химия:"; cin >> stud1[i].points.chemistry;
        stud1[i].average = (stud1[i].points.physics + stud1[i].points.math + stud1[i].points.chemistry)/3;
        cin.get();
    }
cout << "Сортируемб" << "\n";
for (int i=0; i<numb; i++)
{
    for(int j=i++; j<numb;j++)
    {
        if(stud1[i].group>stud1[j].group)
            swap(stud1[i],stud1[j]);
    }
}
int amount = 0;
for (int i=0;i<numb;i++)
{
    if(stud1[i].average>4.0)
        amount++;
}
if (amount==0)
{
    cout << "Умников нет" << "\n";
    return 0;
}
system("cls");
setlocale(LC_ALL,"rus");
cout << "Вывод хорошистов \n";
cout << "Фамилия\t" << "Группа\t" << endl;
cout << "=================================================================" << endl;
for (int i=0; i<numb; i++)
{
    if (stud1[i].average>4.0)
    {
        cout << stud1[i].name << "\t" << stud1[i].group << "\t\n";
    }
}
    return 0;
}
