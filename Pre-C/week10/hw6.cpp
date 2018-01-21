#include <iostream>

using namespace std;

/*
11 4
15 3 76 67 84 87 13 67 45 34 45
67 45 34 45 15 3 76 67 84 87 13

*/
int main()
{
    int a[100];
    int n = 0, m = 0;
    cin >> n >> m;
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int tmp = 0;
    for (int i = 0; i < m; i++)
    {
        tmp = a[n - 1];
        for (int j = n - 1; j > 0; j--)
        {
            a[j] = a[j - 1];
        }
        a[0] = tmp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}