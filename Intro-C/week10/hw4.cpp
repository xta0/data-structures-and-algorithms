#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    //int a[5][5] = {{1, 2, 2, 1, 2}, {5, 6, 7, 8, 3}, {9, 3, 0, 5, 3}, {7, 2, 1, 4, 6}, {3, 0, 8, 2, 4}};

    int a[5][5] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin>>a[i][j];
        }
    }


    int n = 0, m = 0;
    cin >> n >> m;

    if( n > 4 || n<0 || m>4 || m<0 ){
        cout <<"error"<<endl;
        return -1;
    }

    int tmp = 0;
    for (int i = 0; i < 5; i++)
    {
        tmp = a[n][i];
        a[n][i] = a[m][i];
        a[m][i] = tmp;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << setw(4) << a[i][j];
        }
        cout << endl;
    }

    return 0;
}