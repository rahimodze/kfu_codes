#include <iostream>
using namespace std;
class matrix
{
    private:
    double x[3][3]; // по-другому никак, иначе опять динамический массив
    public:
        void fillin()
        {
            for (int i=1;i<=3; i++)
            {
                for (int j=1;j<=3;j++)
                {
                    cout << "enter x[" << i << "][" << j << "]:";
                    cin >> x[i][j];
                }
            }
        }
        void getmax()
        {
            int Max=0;
            for (int i=1;i<=3; i++)
            {
                for (int j=1;j<=3;j++)
                {
                    if(Max<x[i][j])
                        Max = x[i][j];
                }
            }
            cout << "maximum element:" << Max << endl;
        }
        matrix()
        {
            fillin();
        }
        ~matrix()
        {
            cout << "deleted." << endl;
        }
};

int main()
{
    matrix berb;
    berb.getmax();
    system("pause");
    return 0;
}
