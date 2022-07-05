#include <iostream>
using namespace std;

int main()
{
double *x;
int n;
cout << "enter array size:"; cin >>n;
x = new double[n];
for (int i=1;i<=n;i++)
{
    cout << "enter x[" << i << "]";
    cin >> *(x+i);
    cout << "x[" << i << "]=" << *(x+i) << endl;
}
cin.clear();
bool deletion = 0;
cout << "do you want to clear array memory?\n0 for no, 1 for yes.\n"; cin >> deletion;
switch(deletion)
{
case true:
    delete[] x;
    cout << "deleted" << endl;
    break;
case false:
    cout << "left in ram" << endl;
    break;
}
cout << "Done.";
    return 0;
}
