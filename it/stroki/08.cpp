#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    setlocale(LC_ALL,"russian");
string s;
int id = 0;
int maximum = 0;
int chet = 0;
int dlina;
cout << "¬ведите строку с несколькими словами:";
getline(cin,s);
dlina = s.length();
for (int i=0; i<dlina; i++)
{


        if (s[i] != ' ') chet += 1;
        else
        {
            if (chet > maximum)
            {
                maximum = chet;
                id = i - chet;
            }
            chet = 0;
        }
    if (chet > maximum) {
        maximum = chet;
        id = i - chet;
    }
}
int konec = maximum + id;
cout << "длина самого большого слова -> " << maximum << endl;
cout << "—амо слово:";
    for (int i=id; i<=konec; i++)
        cout << s[i];
cout << "\n";
return 0;
}
