#include <iostream>
#include <iomanip>
using namespace std;
int main() {
    int n;
    cin >> n;
    cout<<hex<<n<<endl;
    cout.fill('0');
    cout<<dec<<setw(10)<<n<<endl;
    return 0;
}