#include <stdio.h>

void quick_sort(int* input, int len){
  if (len == 1) {
    return;
  }
  
  int mid = input[0];
  int i=1, j=len-1;

  while (i!=j){
    
    
  }
  
  input[j]=mid;

     int tmp = input[i+1];
      input[i+1] = input[j];
      input[j] = tmp;
}


int main(){



  return 0;
}
