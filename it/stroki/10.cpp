#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
cout << "������� ���� � ������" << endl;
string x;
cout << "������� ����������� - ',' '.' ' '\n";
cout << "������� ������:";
getline(cin,x);
int colvo = 1;
if (x.empty()==true)
{
    cout << "������ �����.\n";
    return 0;
}
for (int i=0; i<x.length(); i++)
    {
        if(((x[i]==',') | (x[i]=='.') | (x[i]==' ')) && ((x[i-1]!=',') && (x[i-1]!='.') && (x[i-1]!=' ')))
        {
            colvo++;
        }
    }
cout << "Done. ���������� ���� - " << colvo << endl;
    return 0;
}
