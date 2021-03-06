#include <iostream>
#include <random>

using namespace std;

int main()
{
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dist(0, 1); //Use `dist` to transform the random unsigned int generated by gen into an int in [0, 1]
    int n1; int n2; int d;
    cout << "enter n1:"; cin >> n1;
    cout << "enter n2:"; cin >> n2;
    cout << "enter iterations:"; cin >> d;
    int q = n1;
    int m = n2;
    //int k[d];
    int k1 = 0;
    int k2= 0;
    for(int i=0;i<d;i++)
    {
    //k[i]=0;
    while ((n1>0) & (n2>0))
        {
            if(dist(gen)==0)
            {
                n1--;
                n2++;
            }
            else
            {
                n1++;
                n2--;
            }
    //k[i]++;
        }
    if(n1==0)
    {
        k2++;
    }
    else
    {
        k1++;
    }
    n1= q;
    n2 = m;
    }
    cout << "first player's wins:" << k1 << endl;
    cout << "second player's wins:" << k2 << endl;
    cout << "fin." << endl;
    return 0;
}
