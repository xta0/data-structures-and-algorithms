#include <stdio.h>

int* merge_sort(int* p, int n){

    if(n>2){
        int *p1 = merge_sort(p,n/2);
        int *p2 = merge_sort(p+n/2, n-n/2);
    }
 
}

int main(){



    return 0;
}