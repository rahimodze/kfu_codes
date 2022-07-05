#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
//setprecision(6);
template <class func>


double integralus(double a, double b, int n, func d)
{
    double h = fabs(b-a)/(2*n);
    double sum1 = d(a) + d(b);
    for(int i=1;i<2*n; i++)
    {
        if(i%2==0)
        {
            sum1+=2*d(a+i*h);
            continue;
        }
            sum1+=4*d(a+i*h);
    }
    return sum1*h/3;
}
double infiniter(double eps, int signum)
{
return signum * (1-eps)/(1-pow(1-eps,2));
}
double my_func(double x)
{
    return x*x;
}
double error(double e)
{
    double x = e / (1 - pow(e , 2));
    double j = (1 + pow(e,2)) / pow(1 - pow(e,2), 2);
    return j * exp(-1 * pow( x ,2));
}
int main()
{
    cout << "Hello world!" << endl;
    float left = 0;
    cout << "enter left border:";
    cin >> left;
    float right = 0;
    cout << "enter right border:";
    cin >> right;
    int kolvo = 0;
    cout << "enter number of steps:";
    cin >> kolvo;
    double eps; cout << "enter eps:"; cin >> eps;
cout << setprecision(7) << "parabola == " << integralus(left,right,kolvo,my_func) << endl;
cout << "newton-leibniz == " << (pow(right,3)-pow(left,3))/3 << endl;
//cout << setprecision(15) << "pi == " << pow(integralus(-1.0+eps, 1.0-eps, kolvo, error),2) << endl;
    return 0;
}
