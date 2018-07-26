#include <iostream>
#include <math.h>

using namespace std;
int main(){
    const int n = 6;
    int max_odd=0;
    int min_even=0xfffffff;
    int x = 0;
    for(int i=0; i<n; i++){
         cin >> x;
         if( x%2 == 1){
             if(x > max_odd){
                 max_odd = x;
             }
         }
         else{
             if (x < min_even){
                 min_even = x;
             }
         }
    }
    cout <<fabs(max_odd - min_even);
    
    return 0;
}