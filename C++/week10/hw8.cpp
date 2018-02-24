#include <bitset>
#include <iostream>

using namespace std;
const int N = 2^30;
int main(){
    int t=0;
    cin>>t;
    for(int p=0;p<t;p++){
        int n,i,j;
        cin >> n >> i >>j;
        bitset<N> bn = n;
        bitset<N> bk;
        bk.reset(); //其他位都是0
        bk[i] = bn[i]; //第i位和n相同
        bk[j] = bn[j]==1?0:1; //第j位和n不同
        int ii = i+1;
        for(;ii<j;ii++){
            bk[ii]=1;
        }
        unsigned long k = bk.to_ulong();
        cout<<hex<<k<<endl;
    }
    return 0;
}
