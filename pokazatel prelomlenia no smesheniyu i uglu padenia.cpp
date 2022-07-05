#include <iostream>
#include <cmath>
using namespace std;

int main()
{
double const h = 10;
double l;
double a;
double const pi = 3.141592653589793;
cout << "vvedite ugol:";cin >> a;
cout << "vvedite smeshenie:";cin >> l;
double sinus = sin(a * pi / 180);
double cosinus = cos(a * pi / 180);
cout << "prelomlenie ravno:" << sqrt(pow((cosinus * sinus / (sinus - l / h)),2) + pow(sinus,2)) << endl;

    return 0;
}
