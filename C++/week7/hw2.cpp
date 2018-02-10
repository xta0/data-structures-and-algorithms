#include <iostream>
using namespace std;
int main() {
    double n;
    cin >> n;
    cout.setf(ios::fixed);
    cout.precision(5);
    cout << n << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout.precision(7);
    cout << n << endl;
    return 0;
}