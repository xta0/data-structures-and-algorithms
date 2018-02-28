#include <stdio.h>
void print_array(const char *title, const int *list, int len)
{
    printf("%s\n", title);   
    for (int i = 0; i < len; ++i){
        printf("%d,", list[i]);
    }
}