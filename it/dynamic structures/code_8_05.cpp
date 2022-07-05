#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
struct item
{
    int position;
    string name;
    string description;
    string origin;
    string manufacturer;
    string category;
    float price;
    float weight;
} *p1;
void show(item *p)
{
    cout << "name:" << p->name << endl;
    cout << "description:\n" << p->description << endl;
    cout << "origin:" << p->origin << endl;
    cout << "manufacturer:" << p->manufacturer << endl;
    cout << "category:" << p->category << endl;
    cout << "price:" << setprecision(2) << p->price << endl;
    cout << "weight:" << setprecision(2) << p->category << endl;
}
int main()
{
item* spisok = new item[10];
for (int i=1; i<=10; i++)
{
    (spisok+i)->position = i;
    cout << "enter product's name:";
    getline(cin,(spisok+i)->name);
    //cin.ignore();
    cout << "enter product's desription:";
    getline(cin,(spisok+i)->description);
    //cin.ignore();
    cout << "enter product's country origin:";
    getline(cin,(spisok+i)->origin);
    //cin.ignore();
    cout << "enter product's manufacturer:";
    getline(cin,(spisok+i)->manufacturer);
    //cin.ignore();
    cout << "enter product's category:";
    getline(cin,(spisok+i)->category);
    //cin.ignore();
    cout << "enter product's price in roubles:";
    cin >> (spisok+i)->price;
    //cin.ignore();
    cout << "enter product's weight in kg:";
    cin >> (spisok+i)->weight;
    cin.ignore();
    show(spisok+i);
}
string key1;
cout << "enter keyword for search by names:"; getline(cin,key1);
for (int i=1;i<=10;i++)
{
    if((spisok+i)->name.find(key1)!=string::npos)
    {
        cout << "found next item:" << endl;
        show(spisok+i);
    }
}
string key2;
cout << "enter keyword for search by description:"; getline(cin,key2);
for (int i=1;i<=10;i++)
{
    if((spisok+i)->description.find(key2)!=string::npos)
    {
        cout << "found next item:" << endl;
        show(spisok+i);
    }
}
float supreme;
float infinum;
cout << "enter upper border:"; cin >> supreme;
cout << "enter lower border:"; cin >> infinum;
for (int i=1;i<=10;i++)
{
    if(((spisok+i)->price<=supreme) && ((spisok+i)->price>=infinum))
    {
        cout << "found next item:" << endl;
        show(spisok+i);
    }
}
    return 0;
}
