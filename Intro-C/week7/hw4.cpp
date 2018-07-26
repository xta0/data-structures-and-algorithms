#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    cin >> x;

    int t100 = x / 100;
    int t50 = (x - t100 * 100) / 50;
    int t20 = (x - t100 * 100 - t50 * 50) / 20;
    int t10 = (x - t100 * 100 - t50 * 50 - t20 * 20) / 10;
    int t5 = (x - t100 * 100 - t50 * 50 - t20 * 20 - t10 * 10) / 5;
    int t1 = (x - t100 * 100 - t50 * 50 - t20 * 20 - t10 * 10 - t5 * 5);
    cout << t100 << "\n";
    cout << t50 << "\n";
    cout << t20 << "\n";
    cout << t10 << "\n";
    cout << t5 << "\n";
    cout << t1 << "\n";
    return 0;
}