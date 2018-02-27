#include <stdio.h>

void print_array(const char *title, const int *list, int len)
{
    
    printf("%s\n", title);
    
    for (int i = 0; i < len; ++i)
    {
        printf("%d,", list[i]);
    }
}

/*
 一共n个数，n-1次循环，时间复杂度n的平方
 思路：
 （1）一次归为一个数，这个数是当前轮次的最大数或者最小数
 （2）内外层循环从0开始，将最大值或最小值冒泡到队尾
 */
void bubble_sort(int *list, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        printf("round:%d\n", i);
        for (int j = 0; j < len - (i + 1); j++)
        {
            printf("list[%d]:%d,", j, list[j]);
            printf("list[%d]:%d", j + 1, list[j + 1]);
            if (list[j] < list[j + 1])
            {
                printf(",交换：%d,%d",list[j],list[j+1]);
                int tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
            print_array("", list, len);
            printf("\n");
        }
        printf("-------\n");
    }
}



int main()
{
    printf("输入7个数：\n");
    int tmp;
    int a[7];
    for (int i = 0; i < 7; i++)
    {
        scanf("%d", &tmp);
        a[i] = tmp;
    }
    
    print_array("before sort: ", a, 7);
    bubble_sort(a, 7);
    print_array("after sort: ", a, 7);
    
    return 1;
}
