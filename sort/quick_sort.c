#include <stdio.h>
#include "header.h"

void sort(int *input, int l, int r)
{
    if(l >= r)
        return;
    
    int pivot = input[l];
    int i=l;
    int j=r;
    while(i!=j){
        while(input[j]>=pivot && j>i){
            j--;
        }
        while(input[i]<=pivot && j>i){
            i++;
        }
        if(j>i){
            //swap
            int tmp = input[i];
            input[i] = input[j];
            input[j] = tmp;
        }
    }

    //swap pivot
    input[l] = input[i];
    input[i] = pivot;
    
    //recursion
    sort(input,l,i-1);
    sort(input,i+1,r);
}

int main()
{
    int a[9] = {4, 6, 5, 2, 9, 3, 1, 7, 8};
    print_array("before sort", a, 9);
    sort(a,0,8);
    print_array("after sort", a, 9);
    return 0;
}
