#include <iostream>
#include <string>
using namespace std;
class children
{
private:
string name;
string surname;
string last_name;
int age;
public:
void getname()
{
cout << "Enter name:";getline(std::cin,name);
}
void outname()
{
cout << "children's name:" << name << endl;
}
void getsurname()
{
cout << "Enter surname:";getline(std::cin,surname);
}
void outsurname()
{
cout << "children's surname:" << surname << endl;
}
void setlast_name()
{
cout << "enter last name:";getline(std::cin,last_name);
}
void outlast_name()
{
cout << "children's last name:" << last_name << endl;
}
void setage()
{
cout << "enter age:";cin >> age;cin.ignore();
}
void outage()
{
cout << "children's age:" << age << endl;
}
};

int main()
{
children* x = new children[2];
for (int i=0; i<2; i++)
{
    (x+i)->getname();
    (x+i)->outname();
    (x+i)->getsurname();
    (x+i)->outsurname();
    (x+i)->setlast_name();
    (x+i)->outlast_name();
    (x+i)->setage();
    (x+i)->outage();

}
    return 0;
}
