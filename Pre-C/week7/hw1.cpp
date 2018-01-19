#include <iostream>
#include <iomanip>

using namespace std;
int main()
{

    int n = 0, x = 0;
    cin >> n;
    double a_0118 = 0, a_1935 = 0, a_3660 = 0, a_61 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x > 0 && x <= 18)
        {
            a_0118++;
        }
        else if (x > 18 && x <= 35)
        {
            a_1935++;
        }
        else if (x > 36 && x <= 60)
        {
            a_3660++;
        }
        else
        {
            a_61++;
        }
    }
    cout << "1-18: " << fixed << setprecision(2) << a_0118 / n * 100 << "%"<<"\n";
    cout << "19-35: " << fixed << setprecision(2) << a_1935 / n * 100 << "%"<<"\n";
    cout << "36-60: " << fixed << setprecision(2) << a_3660 / n * 100 << "%"<<"\n";
    cout << "60-: " << fixed << setprecision(2) << a_61 / n * 100 << "%"<<"\n";

    return 0;
}