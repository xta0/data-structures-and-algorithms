#include <iostream>

using namespace std;

int main()
{
    char s[80];
    cin.getline(s, 80);
    int a, e, i, o, u;
    for (int k = 0; k < 80; k++)
    {
        if (s[k] == 'a')
        {
            a++;
        }
        if (s[k] == 'e')
        {
            e++;
        }
        if (s[k] == 'i')
        {
            i++;
        }
        if (s[k] == 'o')
        {
            o++;
        }
        if (s[k] == 'u')
        {
            u++;
        }
    }
    cout << a <<endl;
    cout << e <<endl;
    cout << i <<endl;
    cout << o <<endl;
    cout << u <<endl;
    return 0;
}