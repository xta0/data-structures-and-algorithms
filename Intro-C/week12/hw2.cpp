#include <iostream>

using namespace std;
int main()
{
    int x = 0;
    bool r = false;
    while (cin >> x)
    {
        if (x % 3 == 0)
        {
            cout << "3 ";
            r = true;
        }
        if (x % 5 == 0)
        {
            cout << "5 ";
            r = true;
        }
        if (x % 7 == 0)
        {
            r = true;
            cout << "7";
        }
        if (!r){
            cout << 'n'; 
        }
        cout<< endl;
        r = false;
    }
    return 0;
}