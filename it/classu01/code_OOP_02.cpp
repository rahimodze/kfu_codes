#include <iostream>

using namespace std;
class number
{
private:
    int Number;
public:
void OutNumber();
void SetNumber();
};

    void number::SetNumber()
    {
    cout << "Enter number:";cin >> Number;
    }
    void number::OutNumber()
    {
    cout << "Number equal to " << Number << endl;
    }
int main()
{
number value1;
number value2;
value1.SetNumber();
value1.OutNumber();
value2.SetNumber();
value2.OutNumber();
    return 0;
}
