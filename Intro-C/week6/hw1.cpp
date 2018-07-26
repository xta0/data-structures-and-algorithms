#include <iostream>
#include <math.h>

using namespace std;
int main(){

    double n,x,y=0;
    cin >> n >> x >> y;
    int t = ceil(y/x);
    if(t>=n){
        t=n;
    }
    int z = n-t;
    cout <<z;
    return 0;
}