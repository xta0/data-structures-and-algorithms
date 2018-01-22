#include <iostream>
#include <iomanip>
using namespace std;
/*
5
....#
.#.@.
.#@..
#....
.....
4
*/
//16

inline bool can_move_left(int n, int j)
{
    if (j > 0 && j <= n - 1)
    {
        return true;
    }
    return false;
}

inline bool can_move_right(int n, int j)
{
    if (j >= 0 && j < n - 1)
    {
        return true;
    }
    return false;
}

inline bool can_move_up(int n, int i)
{
    if (i <= n - 1 && i > 0)
    {
        return true;
    }
    return false;
}

inline bool can_move_down(int n, int i)
{
    if (i >= 0 && i < n - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int n = 0;
    cin >> n;
    char a[100][100];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int m = 0;
    cin >> m;

    for (int k = 1; k <= m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '*')
                {
                    a[i][j] = '@';
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '@')
                {

                    if (can_move_up(n, i))
                    {
                        if (a[i - 1][j] == '.')
                        {
                            a[i - 1][j] = '*';
                        }
                    }

                    if (can_move_down(n, i))
                    {
                        if (a[i + 1][j] == '.')
                        {
                            a[i + 1][j] = '*';
                        }
                    }

                    if (can_move_right(n, j))
                    {
                        if (a[i][j + 1] == '.')
                        {
                            a[i][j + 1] = '*';
                        }
                    }

                    if (can_move_left(n, j))
                    {
                        if (a[i][j - 1] == '.')
                        {
                            a[i][j - 1] = '*';
                        }
                    }
                }
            }
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '@')
            {
                result++;
            }
        }
    }
    cout << result;

    return 0;
}