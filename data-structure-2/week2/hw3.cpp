#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int comp(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main()
{
    int n, t;
    cin >> n >> t;
    if (t < 0)
        t *= -1;
    int *a;
    a = new int[n];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }
    qsort(a, n, sizeof(int), comp);
    int ans = 0;
    int index1 = 0, index2 = 1;
    while (index1 < n && index2 < n)
    {
        if (index1 >= index2)
            index2++;
        if (index1 > 0 && index2 > 0)
        {
            while (a[index1] == a[index1 - 1])
                ++index1;
            while (a[index2] == a[index2 - 1])
                ++index2;
            if (index1 >= n || index2 >= n)
                break;
        }
        if (a[index2] - a[index1] == t)
        {
            ++ans;
            ++index2;
            ++index1;
            continue;
        }
        if (a[index2] - a[index1] > t)
        {
            ++index1;
            continue;
        }
        if (a[index2] - a[index1] < t)
        {
            ++index2;
            continue;
        }
    }
    cout << ans;

    return 0;
}