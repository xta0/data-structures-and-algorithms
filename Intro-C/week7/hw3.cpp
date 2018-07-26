#include <iostream>

using namespace std;

void partition(int *p, int l, int r)
{
    if (r - l < 0)
    {
        return;
    }
    int piviot = p[l];
    int i = l, j = r;
    while (i != j)
    {

        while (p[j] <= piviot && j > i)
        {
            j--;
        }
        while (p[i] >= piviot && i < j)
        {
            i++;
        }

        int tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
    }

    //i=j;
    p[l] = p[i];
    p[i] = piviot;

    //left part recursion
    partition(p, l, i-1);

    //right part recursion
    partition(p, i + 1, r);
}

int main()
{
    int a[100];
    int k=0,n=0;
    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    partition(a, 0, n-1);

    // cout << "after sort: "<<"\n";
    // for (int z = 0; z < n; z++)
    // {
    //     cout << a[z] << " ";
    // }
    cout << a[k-1];
    return 0;
}