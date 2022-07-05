#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;
int main()
{
setlocale(LC_ALL, "rus");
int n = 14;
int chet = 0;
int nechet = 0;
int x[n];
int t[n];
srand(time(0));
ofstream f("f.txt");
for (int i=0; i<n; i++)
{
    x[i]=1+rand()%100;
    cout << x[i] << "\t";
    f << x[i] << "\t";
}
f.close();
cout << endl;
ifstream fin("f.txt");
for (int i=0; i<n; i++)
{
    t[i]=0;
    fin >> t[i];
    cout << t[i] << "\t";
        if(t[i]%2==0)
            chet++;
        else
            nechet++;
}
fin.close();
cout << endl;
cout << "Число нечетных = " << nechet << endl;
cout << "Число четных = " << chet << endl;
int y[chet];
int z[nechet];
int j = 0;
int k = 0;
for (int i = 0; i<n; i++)
{
    if(t[i]%2==0)
    {
        y[j]=0;
        y[j]=t[i];
        j++;
    }
    else
        {
        z[k]=0;
        z[k]=t[i];
        k++;
        }
}
ofstream g("g.txt");
cout << "Запись четных значений в g.txt" << endl;
for(int i=0;i<chet;i++)
{
    cout << y[i] << "\t";
    g << y[i] << "\t";
}
cout << endl;
g.close();
ofstream h("h.txt");
cout << "Запись нечетных значений в h.txt" << endl;
for(int i=0;i<nechet;i++)
{
    cout << z[i] << "\t";
    h << z[i] << "\t";
}
cout << endl;
h.close();
    return 0;
}
