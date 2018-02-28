#include <stdio.h>
#include "header.h"

typedef struct {
    int *p;
    int len;
}TUPLE;

TUPLE merge_sort(int* p, int n){

    if(n>2){
        TUPLE t1 = merge_sort(p,n/2);
        TUPLE t2 = merge_sort(p+n/2-1, n-n/2);
        //merge
        int len1 = t1.len;
        int len2 = t2.len;
        int i=0,j=0;
        for(int k=0;k<len1+len2;k++){
            if(t1.p[i] < t2.p[j]){
                
                
            }else{
                //swap
                int tmp = t1.p[i];
                t1.p[i] = t2.p[j];
                t2.p[j] = tmp;
                i++;
            }
        }
        
    }else{
        if(n == 1){
            return (TUPLE){p,1};
        }
        else if(n==2){
            if(p[0] > p[1]){
                //swap
                int tmp = p[0];
                p[0] = p[1];
                p[1] = tmp;
            }
            return (TUPLE){p,2};
        }
        else{
            printf("wrong!");
            return (TUPLE){p,0};
        }
    }
}



int main(){

    int a[8] = {4,6,5,2,3,1,7,8};
    print_array("before sort", a, 8);
    TUPLE ret = merge_sort(a,8);
    print_array("after sort",ret.p,ret.len);

    return 0;
}