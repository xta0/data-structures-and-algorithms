
#include <iostream>

using namespace std;
int main()
{

    int n = 0, k = 0;
    cin >> n >> k;

    int s = 200;
    int i = n;
    int y = 1;
    while (i < s)
    {
        i = i + n;
        s = s + s * (k / 100.0);
        y++;
        if (y > 20)
        {
            break;
        }
    }
    if (y <= 20)
    {
        cout << y << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}
