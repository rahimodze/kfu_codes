#include <iostream>
#include <iomanip>
using namespace std;

class myArray
{
private:
    int n;
    double *beb = new double[n];
public:
    void setsize()
    {
        cout << "enter array's size";cin >> n;
    }
    void fillelements()
    {
        for(int i=1; i<=n; i++)
        {
            cout << "enter x[" << i << "]:";
            cin >> *(beb+i);
        }
    }
    void getmax()
    {
        int Max=0;
        for(int i=1; i<=n; i++)
        {
            if(Max<*(beb+i))
                Max = *(beb+i);
        }
        cout << "maximim:" << Max << endl;
    }
    void showelements()
    {
        for(int i=1; i<=n; i++)
        {
            cout << "x[" << i << "] = " << *(beb+i) << endl;
        }

    }
    myArray()
    {

    };
    myArray(int p)
    {
        cout << "configured constructor has been used." << endl;
        n = p;
        fillelements();
    }
    ~myArray()
    {

    }
};
int main()
{
    myArray borba(4);
    borba.showelements();
    borba.getmax();
    return 0;
}
