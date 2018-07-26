#include <iostream>
#include <math.h>

using namespace std;
int main()
{

    int x = 0;
    cin >> x;

    if (x >= 95 && x <= 100)
    {
        cout << 1 << "\n";
    }
    else if (x >= 90 && x < 95)
    {
        cout << 2 << "\n";
    }
    else if (x >= 85 && x < 90)
    {
        cout << 3 << "\n";
    }
    else if (x >= 80 && x < 85)
    {
        cout << 4 << "\n";
    }
    else if (x >= 70 && x < 80)
    {
        cout << 5 << "\n";
    }
    else if (x >= 60 && x < 70)
    {

        cout << 6 << "\n";
    }
    else
    {
        cout << 7 << "\n";
    }

    return 0;
}