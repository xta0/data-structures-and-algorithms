#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int main() {
    int n;
    int cases=0;
    string P;
    while(cin>>n && n!=0) {
        vector<int> next(n, 0);
        cin>>P;
        next[0]=0;
        int j=0;
        for(int i=1; i<n; i++) {
            int j=next[i-1];  //j表示当前匹配了多少位
            while(j && P[j]!=P[i]) 
                j=next[j-1];
            if (P[j]==P[i]) {
                next[i]=j+1;
            }
            else {
                next[i]=0;
            }
        }
        cout << "Test case #" << ++cases << endl;
        for(int i=2; i<=n; i++) {
            if (i%(i-next[i-1])==0 && i/(i-next[i-1]) > 1) {
                cout << i << " " << i/(i-next[i-1]) << endl;
            }
        }
        cout << endl;
    }
    return 0;
}