#include <iostream>
#include <string.h>

using namespace std;

void swap_word(char *p, int s, int len)
{

    for (int i = 0; i < len / 2; i++)
    {
        int tmp = p[i + s];
        p[i + s] = p[len - i - 1 + s];
        p[len - i - 1 + s] = tmp;
    }
}

int main()
{

    char input[500];
    cin.getline(input, 500);
    unsigned long l = strlen(input);
    input[l] = ' ';

    int len = 0;
    for (int i = 0; i <= l; i++)
    {
        char c = input[i];
        if (c != ' ')
        {
            len++;
        }
        else
        {
            if (len != 0)
            {
                swap_word(input, i - len, len);
                len = 0;
            }
        }
    }
    for (int i = 0; i < l; i++)
    {
        cout << input[i];
    }
    return 1;
}
