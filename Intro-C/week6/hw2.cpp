#include <iostream>
#include <math.h>

using namespace std;
int main(){

    const int m = 20*1000;
    int h,r = 0;
    cin>> h >> r;
    double vol = M_PI * r * r * h;
    int n = ceil (m / vol);
    cout <<n;

    return 0;
}