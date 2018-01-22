#include <iostream>
using namespace std;

/*
第一组
6
-2 -1 7 3 4 8
第二组
6
9 9 9 9 9 9

*/
int main(){

    int n=0;
    cin>>n;
    int x[100]={0};
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    int r = -1;
    for(int i=0;i<n;i++){
        if (x[i] == i){
            r= i;
            break;
        }
    }
    if(r==-1){
        cout <<"N";
    }
    else{
        cout<<r;
    }
    return 0;
}