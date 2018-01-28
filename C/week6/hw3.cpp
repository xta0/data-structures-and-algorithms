#include <stdio.h>

using namespace std;
int main(){

    int m=0,n=0;
    scanf("%d%d",&m,&n);
    int a[m][n];
    
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int left=0,right=0,top=0,bottom=0;
    for(int i=0;i<m;i++){
        for(int j=0; j<n;j++){

            int x = a[i][j];
            //left:
            if(j-1>=0){
                left=a[i][j-1];
            }
            //right:
            if(j+1<n){
                right=a[i][j+1];
            }
            //top:
            if(i-1>=0){
                top=a[i-1][j];
            }
            if(i+1<m){
                bottom=a[i+1][j];
            }
            if( x>=left &&
                x>=right&&
                x>=top &&
                x>=bottom)
            {
                printf("%d %d\n",i,j);
            }
            left=right=top=bottom=0;
        }
    }
    return 0;
}