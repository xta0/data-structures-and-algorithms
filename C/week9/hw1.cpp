#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{

    char m[100000];
    int k = 0;
    cin >> m >> k;
    int len = strlen(m);

    int s = 0;
    for (int i = 0; i < len; i++)
    {
        if (m[i] == '3')
        {
            s++;
        }
    }
    if (s == k)
    {   
        long x = atol(m);
        if( x%19 == 0 ){
            cout<<"YES";
        }else{
            cout<<"NO";
        }

    }else{
        cout<<"NO";
    }

    return 0;
}