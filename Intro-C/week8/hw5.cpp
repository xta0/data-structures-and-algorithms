#include <iostream>
using namespace std;

int main()
{

    int n = 0;
    cin >> n;

    for (int i = 10; i <= n; i++)
    {
        int t = i / 10;
        int m = i % 10;
        if (i % (t + m) == 0)
        {
            cout << i << endl;
        }
    }

    return 0;
}