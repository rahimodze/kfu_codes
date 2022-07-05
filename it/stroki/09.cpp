#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
setlocale(LC_ALL, "rus");
cout << "Поиск символа '-' в строке" << endl;
string x;
ifstream in("file.txt");
getline(in,x);
in.close();
int k = x.length();
int colvo = 0;
for (int i=0; i<k; i++)
    {
        if(x[i]=='-')
        {
            colvo++;
        }
    }
cout << "Done. Количество минусов - " << colvo << endl;
    return 0;
}
