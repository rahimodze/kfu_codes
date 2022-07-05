#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int current = 2021;
class book
{
private:
    string title;
    int pages;
    int year;
    double price;
public:
    void setname()
    {
        cout << "enter title:";
        cin.ignore();
        getline(cin,title);
    }
    void setpages()
    {
        cout << "enter amount of pages:";cin >> pages;
    }
    void setyear()
    {
        cout << "enter year of publication:";
        cin >> year;
    }
    void setprice()
    {
        cout << "how much does it cost?:";
        cin >> price;
    }
    void averageprice()
    {
        cout << "price for page:" << setprecision(4) << price/pages << endl;
    }
    void daycounter()
    {
        cout << "days since released:" << (current - year)*365 << endl;
    }
    void yearcounter()
    {
        cout << "book is " << current - year << " years old." << endl;
    }
    book()
    {
        cout << "empty constructor worked" << endl;
    };
    book(string a, int b, int c, double d)
    {
        cout << "parametred constructor worked" << endl;
        title = a;
        pages = b;
        year = c;
        price = d;
    }
    ~book()
    {
        cout << "object terminated" << endl;
    }
    void showspecs()
    {
        cout << "title:" << title << endl;
        cout << "pages:" << pages << endl;
        cout << "publication:" << year << endl;
        cout << "price:" << price << '$' << endl;
    }
};
int main()
{

    book wap("war and peace",1500,1869,669);
    wap.showspecs();
    wap.daycounter();
    wap.yearcounter();
    wap.averageprice();
    return 0;
}
