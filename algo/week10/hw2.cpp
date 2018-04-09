#include <iostream>
using namespace std;

int gcd(int x, int y)
{
    if(x == y){
        return x;
    }
    int mx = max(x,y);
    int mn = min(x,y); 
    int diff = mx - mn;
    return gcd (diff, mn); 
}

int main()
{
    int m=0, n=0;
    while(cin>>m>>n){
        cout<<gcd(m,n)<<endl;
    }
    return 0;
}