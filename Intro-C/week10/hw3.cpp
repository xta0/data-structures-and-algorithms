#include <iostream>

using namespace std;
/*
I am a student of Peking University.
*/
int main()
{
    int l = 0;
    int index = 0;
    int ori_index = 0;
    char s[500];
    cin.getline(s, 500);
    for (int i = 0; i < 500; i++)
    {
        if (s[i] == ' ' || s[i] == '.')
        {
            int tmp = index == 0 ? (i - index) : (i - index - 1);
            index = i;

            if (tmp > l)
            {
                l = tmp;
                ori_index = index - l;
            }
            if (s[i] == '.')
            {
                break;
            }
        }
    }

    if (l > 0)
    {
        for (int i = ori_index; i < ori_index + l; i++)
        {
            cout << s[i];
        }
    }

    return 0;
}