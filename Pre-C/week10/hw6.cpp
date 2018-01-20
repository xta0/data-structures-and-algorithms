#include <iostream>

using namespace std;

int main()
{
    int a[100];
    int n=0,m=0;
    cin>>n>>m;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=0;i<m;i++){


        a[i+1] = a[i];
    }

    return 0;
}