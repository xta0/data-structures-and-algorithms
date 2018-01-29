#include <stdio.h>


void print_array(const char *title, const int *list, int len)
{
    
    printf("%s\n", title);
    
    for (int i = 0; i < len; ++i)
    {
        printf("%d,", list[i]);
    }
}


void quick_sort(int* input, int len, int l, int r){
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
