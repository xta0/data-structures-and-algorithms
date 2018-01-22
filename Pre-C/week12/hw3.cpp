#include <iostream>
#include <iomanip>
#include <cmath> /* sqrt */

using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    double x[100] = {0};
    double y[100] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        double x1 = x[i];
        double y1 = y[i];

        for (int j = i + 1; j < n; j++)
        {
            double x2 = x[j];
            double y2 = y[j];

            double dis = sqrt(pow((x1 - x2), 2.0) + pow((y1 - y2), 2.0));

            if (dis > max)
            {
                max = dis;
            }
        }
    }
    cout << max;
    return 0;
}