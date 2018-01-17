#include <iostream>

using namespace std;
int main(){

    int n=0;
    cin>>n;

    int max = 0;
    int x = 0;
    for(int i=0; i<n; i++){
        cin >>x;
        if(x > max){
            max = x;
        } 
    }
    cout<<max;
    return 0;
}