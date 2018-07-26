#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    for(int i=0;i<t;i++){
        int n = 0;
        cin>>n;
        int a[n+1][n+2];
        int p[n+1][n+2];
        
        for(int j=0;j<n+2;++j){
            p[0][j] = 0;
        }
        for(int j=1;j<=n;++j){
            p[j][0]=0;
            p[j][n+1]=0;
        }
        cin.get();
        for(int i=1;i<=n;i++){
            string str;
            getline(cin, str);
            for(int j=1;j<=n;j++){
                char x=str[j-1];
                if(x=='y'){
                    a[i][j] = 0;
                }else{
                    a[i][j] = 1;
                }
            }
        }
        //从第一行开始枚举
        for(int i=1;i<=n;i++){
            p[1][i] = 0;
        }
        bool result=false;
        int c=1;
        int max = 1;
        bool invalid = false;
        while(!result){
            for(int i=1; i<=n; ++i){
                for(int j=1; j<=n; ++j){
                    p[i+1][j] = (a[i][j] + p[i][j]+p[i-1][j]+p[i][j-1]+p[i][j+1])%2;
                }
            }
            //验证第n行
            bool r = true;
            for(int i=1;i<=n;i++){
                int x = (p[n][i-1]+p[n][i]+p[n][i+1]+p[n-1][i])%2;
                if(x!=a[n][i]){
                    r = false;
                    break;
                }
            }
            if(!r){
                //如果穷举所有情况后仍不满足条件，则输出“inf”
                if( max > pow(2,n)){
                    invalid = true;
                    break;
                }
                //改变第一行枚举值
                p[1][1]++;
                c=1;
                while(p[1][c]>1){
                    p[1][c]=0;
                    c++;
                    p[1][c]++;
                }
                max++;
                result = false;
                
            }else{
                result = true;
            }
        }
        if(invalid){
            cout <<"inf"<<endl;
        }else{
            int count = 0;
            for(int i=1;i<=n;i++){
                for(int j=0;j<=n;j++){
                    if(p[i][j] == 1){
                        count++;
                    }
                }
            }
            cout<<count<<endl;
        }
    }
    return 0;
}

