#include <iostream>
using namespace std;
const float pi = 3.14159265359;
class circle
{
public:
    float center[2];
    float radius;
    float area;
    float length;
    void getcenter()
    {
        cout << "enter circle center's x coordinate:";cin >> center[1];
        cout << "enter circle center's y coordinate:";cin >> center[2];
    }
    void getrad()
    {
        cout << "enter circle's radius:";cin >> radius;
        if(radius<=0)
        {
            radius = 1;
            cout << "error! incorrect input" << endl;
            getrad();
        }
    }
    void getlength()
    {
        length=2*pi*radius;
    }
    void getarea()
    {
        area=pi*radius*radius;
    }
    void showlength()
    {
        cout << "this circle's length = " << length << endl;
    }
    void showarea()
    {
        cout << "this circle's area = " << area << endl;
    }
};
int main()
{
    cout << "circle basic operations" << endl;
    circle a;
    a.getcenter();
    a.getrad();
    a.getarea();
    a.getlength();
    char k;
    cout << "need to output area? y/n:";cin >> k;
    if(k=='y')
    {
        a.showarea();
    }
    char q;
    cout << "need to output length? y/n:";cin >> q;
    if(q=='y')
    {
        a.showlength();
    }
    cout << "done.";
    return 0;
}
