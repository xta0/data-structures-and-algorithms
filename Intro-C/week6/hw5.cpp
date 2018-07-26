#include <iostream>

using namespace std;
int main(){
    int x =0;
    while(x / 1000 >= 1 || x / 100 == 0) {
        cin >> x;
    }

    int h = x / 100;
    int m = (x - h*100)/10;
    int n = x - h*100 - m*10;

    cout << h <<"\n"<< m<<"\n" << n;  
    return 0;
}