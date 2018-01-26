#include <iostream>
using namespace std;

int main(){

    int x = 3;
    int &y = x;

    int a[3][4] = {{1,3,5,7},{9,11,13,15},{17,19,21,23}};
    int (*p)[4] = a;

    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<*(*(p+i)+j)<<endl; 
            // cout<<p[i][j]<<endl;
        }
    } 
}