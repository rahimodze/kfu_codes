#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//setprecision(6);
template <class func>

double integralus(float a, float b, int n, func d)
{
    float h = (b-a)/n;
    float sum1 = (d(a)+d(b))*h/2;
    for(int i=1;i<n; i++)
    {
    sum1+=d(a+i*h)*h;
    }
    return sum1;
}
double my_func(double x)
{
    return 3*x;
}
int main()
{
    cout << "Hello world!" << endl;
    float left = 0;
    cout << "enter left:"; cin >> left;
    float right = 0;
    cout << "enter right:"; cin >> right;
    int kolvo = 0;
    cout << "enter iterations number:"; cin >> kolvo;
cout << setprecision(7) << "trapezoid == " << integralus(left,right,kolvo,my_func) << endl;
cout << "newton-leibniz == " << 3*(pow(right,2)-pow(left,2))/2 << endl;
    return 0;
}
