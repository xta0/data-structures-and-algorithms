#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

char a[26]={0};
int b[26] = {0};
char c[26]={0};

int i = 0;

void set(char c)
{
    if (isalpha(c))
    {
        char x = c;
        if(x>=97){
            x-=32;
        }
        for(int k=0; k<26; k++){
            if (a[k] == x) {
                b[k]++;
                return ;
            }
        }
        a[i] = x;
        b[i]++;
       i++;
    }
}

int main()
{
    char m[500];
    scanf("%499s",m);

    int len = (int)strlen(m);
    
    for (int i = 0; i < len; i++){
        set(m[i]);
    }
    
//    for(int j=0;j<26;j++){
//        printf("%c ",a[j]);
//    }
//    printf("\n");
//    for(int j=0;j<26;j++){
//        printf("%d ",b[j]);
//    }
//    printf("\n");
    
    //find 2nd biggest
    int max=0;
    for( int i=0; i<25; i++){
        if(b[i]>max){
            max=b[i];
        }
    }
    
    int max_2 = max-1;
    int index_2 = 0;
    bool found=false;
    while(max_2 > 0){
        for(int i=0;i<25;i++){
            if(b[i] == max_2){
                index_2 = i;
                found=true;
                break;
            }
        }
        if(found){
            break;
        }
        max_2=max_2-1;
    }
    
//    printf("2nd biggest index: %d",index_2);
//    printf("\n");
    printf("%c+%c:%d",a[index_2],a[index_2]+32,max_2);
    
    return 0;
}
