#include <stdio.h>

void bubble_sort(int *list, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - (i + 1); j++)
		{
			if (list[j] > list[j + 1])
			{
				int tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
			}
		}
	}
}

void print_array(const char *title, const int *list, int len)
{
	printf("%s\n", title);

	for (int i = 0; i < len; ++i)
	{
		printf("%d,", list[i]);
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