#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
cout << "������� ����������� � ���� � ������" << endl;
string x;
ifstream in("file.txt");
getline(in,x);
in.close();
int k = x.length();
int colvo_slov = 0;
int colvo_predl = 0;
for (int i=0; i<k; i++)
    {
        if(x[i]==' ')
        {
            colvo_slov++;
        }
        if(x[i]=='.')
        {
            colvo_predl++;
        }
    }
cout << "������� ��������. ���������� ���� - " << colvo_slov << ". ���������� ����������� - " << colvo_predl << "." <<  endl;
    return 0;
}
