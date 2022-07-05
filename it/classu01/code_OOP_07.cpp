#include <iostream>
using namespace std;
class sample
{
private:
float x;
float y;
public:
    void setx()
    {
        cout << "enter x:";cin >> x;
    }
    void showx()
    {
        cout << "x = " << x << endl;
    }
    void sety()
    {
        cout << "enter y:";cin >> y;
    }
    void showy()
    {
        cout << "y = " << y << endl;
    }
    void sum()
    {
        cout << "sum = " << x+y << endl;
    }
    void maximum()
    {
        if (x>y)
            cout << "maximum element = " << x << endl;
        else
            cout << "maximum element = " << y << endl;
    }
};

int main()
{
sample dummy;
dummy.setx();
dummy.showx();
dummy.sety();
dummy.showy();
char sum;
cout << "needed sum? (y/n):"; cin >> sum;
if(sum=='y')
    dummy.sum();
char maxx;
cout << "needed maximum? (y/n):"; cin >> maxx; cin.ignore();
if(maxx=='y')
    dummy.maximum();
return 0;
}
