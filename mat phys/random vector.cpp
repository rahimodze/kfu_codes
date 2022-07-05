#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;
double randomizer(double minimum, double maximum)
{
    double noise =  (double)rand()/RAND_MAX;
    return minimum + noise*(maximum-minimum);
}
double infiniter(double eps, int signum)
{
return signum * (1-eps)/(1-pow(1-eps,2));
}
int main()
{
srand(time(NULL));
int i = 1;
long int n = 0;
cout << "enter number of iterations:";
cin >> n;
double kvadrat = 0;
double radius[2] = {0,0};
while (i<n)
{
    double x=randomizer(infiniter(0.001, -1),infiniter(0.001, 1));
    double y=randomizer(infiniter(0.001, -1),infiniter(0.001, 1));
    radius[0]+=x;
    radius[1]+=y;
    kvadrat += pow(radius[0],2)+pow(radius[1],2);
    i++;
}
double average[2] = {radius[0]/n, radius[1]/n};
double translation = pow(radius[0],2)+pow(radius[1],2);
cout << "Radius = (" << radius[0] << ", " << radius[1] << ") \nAverage:\n";
cout <<  average[0] << "\t" << average[1] << endl;
cout << "length of translation:" << translation << endl;
cout << "length of path:" << kvadrat << endl;
    return 0;
}
