#include <iostream>

using namespace std;

void recursion(int x)
{
    if (x == 1)
    {
        cout<<"End"<<endl;
    }
    else
    {
        int value = 0;
        if (x % 2 == 1)
        {
            value = x*3+1;
            cout << x << "*3+1=" <<value<< endl;
            x=value;
        }
        else
        {
            value = x/2;
            cout << x << "/2=" <<value<< endl;
            x=value;
        }
        recursion(x);
    }
}

int main()
{

    int x = 0;
    cin >> x;
    recursion(x);

    return 0;
}