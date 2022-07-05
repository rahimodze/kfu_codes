#include <iostream>
using namespace std;
class rectangle
{
public:
    float length;
    float width;
    float area;
    float perimeter;
    void getlength()
    {
        cout << "enter shape's length:";cin >> length;
            if(length<=0)
        {
            cout << "error! incorrect input" << endl;
            length = 1;
            getlength();
        }
    }
    void getwidth()
    {
        cout << "enter shape's width:";cin >> width;
        if(width<=0)
        {
            cout << "error! incorrect input" << endl;
            width = 1;
            getwidth();
        }
    }
    void getperimeter()
    {
        perimeter=(width+length)*2;
    }
    void getarea()
    {
        area=width*length;
    }
    void showperimeter()
    {
        cout << "this rectangle's perimeter = " << perimeter << endl;
    }
    void showarea()
    {
        cout << "this rectangle's area = " << area << endl;
    }
};
int main()
{
    cout << "rectangle basic operations" << endl;
    rectangle a;
    a.getlength();
    a.getwidth();
    a.getarea();
    a.getperimeter();
    char k;
    cout << "need to output area? y/n:";cin >> k;
    if(k=='y')
    {
        a.showarea();
    }
    char q;
    cout << "need to output perimeter? y/n:";cin >> q;
    if(q=='y')
    {
        a.showperimeter();
    }
    cout << "done.";
    return 0;
}
