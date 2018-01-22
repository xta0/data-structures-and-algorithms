#include <iostream>
#include <iomanip>
using namespace std;

/*
1 5 A 1.0 A 2.0 C 1.0 B 1.0 C 1
3 3 B 1 C 2 C 1
2 4 B 1 A 1 C 1 A 1
*/
/*
1 6.00
2 4.00
3 4.00
A 5.00
B 3.00
C 6.00
*/
int main()
{
    double a[3] = {0};
    double b[3] = {0};

    int id = 0, num = 0;
    for (int i = 0; i < 3; i++)
    {
        cin >> id >> num;
        char type;
        double money;
        for (int j = 0; j < num; j++)
        {
            cin >> type >> money;        
            if (type == 'A')
            {
                b[0] += money;
            }
            if (type == 'B')
            {
                b[1] += money;
            }
            if (type == 'C')
            {
                b[2] += money;
            }

            a[id - 1] += money;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " " << fixed << setprecision(2) << a[i] << endl;
    }
    for (int i = 0; i < 3; i++)
    {
        char c;
        if (i == 0)
        {
            c = 'A';
        }
        if (i == 1)
        {
            c = 'B';
        }
        if (i == 2)
        {
            c = 'C';
        }
        cout << c << " " << fixed << setprecision(2) << b[i] << endl;
    }

    return 0;
}