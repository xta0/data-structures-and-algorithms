#include <iostream>
#include <algorithm>
using namespace std;

int n=0,c=0;
int a[100001];

bool check(int x){
    
    int prev = a[0];
    int cows = 1;
    for(int i=1;i<n;i++){
        if(a[i] - prev > x){
            cows++;
            if(cows == c){
                return true;
            }
            prev=a[i];
        }
        
    }
    return false;
}

int main(){
    
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //sort
    sort(a,a+n);
    
    //binary search
    int l = a[0];
    int r = a[n-1];
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    cout<<l<<endl;
    return 1;
}
