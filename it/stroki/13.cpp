#include <iostream>
#include <string>
using namespace std;

int main()
{
setlocale (0,"");
string a("123456789");
string b("67");
string c("-���������� ����-");
cout << a << endl;
int mesto = a.find(b);
a = a.erase(mesto,2); // remove ������� ������
a = a.insert(mesto,c);
cout << a << endl;
    return 0;
}
