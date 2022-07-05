#include <iostream>
#include <string>
using namespace std;
class employee
{
private:
int number;
float salary;
string name;
public:
    void setnumber()
    {
        cout << "enter employee's personal number:";
        cin >> number;
    }
    void shownumber()
    {
        cout << "this employee's number is " << number << endl;
    }
    void setname()
    {
        cout << "enter employee's name:";
        cin.ignore();
        getline(cin,name);
    }
    void showname()
    {
        cout << "this employee's name is " << name << endl;
    }
    void setsalary()
    {
        cout << "enter employee's salary:";
        cin >> salary;
    }
    void showsalary()
    {
        cout << "this employee's salary equals " << salary << " gold bars." << endl;
    }
};
int main()
{
    cout << "three employees database" << endl;
    employee x[3];
    for (int i=0;i<3;i++)
    {
        cout << "employee ¹" << i+1 << endl;
        x[i].setnumber();
        x[i].shownumber();
        x[i].setname();
        x[i].showname();
        x[i].setsalary();
        x[i].showsalary();
    }
    return 0;
}
