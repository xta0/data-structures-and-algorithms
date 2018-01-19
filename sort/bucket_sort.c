#include <stdio.h>

void bucketSort(int *in, int len, int count)
{
	int temp = 0;
	for (int i = 0; i < count; i++)
	{
		scanf("%d", &temp);
		in[temp]++;
	}

	for (int i = 0; i < len; ++i)
	{
		int numbers = in[i];
		for (int j = 0; j < numbers; j++)
		{
			printf("%d,", i);
		}
	}
}

void empty(int *src, int count)
{
	for (int i = 0; i < 11; i++)
	{
		src[i] = 0;
	}
}

int main(int argc, char **argv)
{
	int a[11];
	empty(a, 11);
	bucketSort(a, 11, 6);

	return 0;
}