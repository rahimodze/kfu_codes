#include <iostream>

using namespace std;
class number
{
private:
    int Number;
public:
    void SetNumber()
    {
    cout << "Enter number:";cin >> Number;
    }
    void OutNumber()
    {
    cout << "Number equal to " << Number << endl;
    }
};
int main()
{
number value;
value.SetNumber();
value.OutNumber();
    return 0;
}
