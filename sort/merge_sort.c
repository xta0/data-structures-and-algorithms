#include <stdio.h>
#include "header.h"

void merge(int a1[], int a2[], int len1, int len2, int* p){
    print_array("\nbefore merge: a1", a1, len1);
    print_array("\nbefore merge: a2", a2, len2);
    int i=0,j=0;
    int len = len1 + len2;
    for(int k=0;k<len;++k ){
        if(i>=len1 && j<len2){
            p[k] = a2[j];
            j++;
            
        }else if (j>=len2 && i<len1){
            p[k] = a1[i];
            i++;
        }else{
            if(a1[i] > a2[j]){
                p[k] = a2[j];
                j++;
            }else{
                p[k] = a1[i];
                i++;
            }
        }
    }
    print_array("\nafter merge: p", p, len);
    printf("\n----");
}

void sort(int* a, int len){
    if(len >= 2){
        int *p1 = a;
        int *p2 = a+len/2;
        int len1 = len/2;
        int len2 = len-len1;
        sort(p1,len1);
        sort(p2,len2);
        int b[len]; //merge to b
        merge(p1, p2,len1, len2, b);
        for(int i=0; i<len; i++){
            a[i] = b[i];
        }
    }
}


int main(){

    int a[9] = {4,6,5,2,9,3,1,7,8};
    print_array("before sort", a, 9);
    sort(a,9);
    print_array("after sort",a,9);

    return 0;
}
