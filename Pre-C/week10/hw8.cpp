#include <iostream>

using namespace std;

int main()
{
    int a[100001]={0};
    int l=0,m=0;
    cin >> l >> m;

    for(int i=0;i<=l;i++){
        a[i]=1;
    }

    int s=0, e=0;
    for(int i=0;i<m; i++){
        cin >> s >> e;
        for(int j=s; j<=e; j++){
            a[j] = 0;
        }
    }
    int result = 0;
    for(int i=0;i<=l;i++){
        if(a[i] == 1){
            result++;
        }
    }
    cout<<result<<endl;


    return 0;
}