#include<iostream>

using namespace std;

int main() {

    int a[100][100];
    int row=0, col=0;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }

    for(int i=0; i<col; i++){
        for(int m=0,n=i; n>=0&&m<row; m++,n--){
            cout<<a[m][n]<<endl;
        }
    }
    for(int j=1;j<row;j++){
        for(int m=j,n=col-1;n>=0&&m<row ;m++,n--){
            cout<<a[m][n]<<endl;
        }
    }
    
    return 0;
}