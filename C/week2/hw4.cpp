#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>

using namespace std;

bool is_leap_year(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void cout_(int x)
{
    if (x < 10)
    {
        cout << setw(2) << setfill('0') << x;
    }
    else
    {
        cout << x;
    }
}

int main()
{

    char buffer[100];
    cin.get(buffer, 100);
    cin.get();

    //tokenize
    int year = atoi(strtok(buffer, "-"));
    int month = atoi(strtok(NULL, "-"));
    int day = atoi(strtok(NULL, "-"));

    if (day == 30)
    {
        if (month == 1 ||
            month == 3 ||
            month == 5 ||
            month == 7 ||
            month == 8 ||
            month == 10 ||
            month == 12)
        {
            day++;
        }
        else
        {
            month++;
            day = 1;
        }
    }
    else if (day == 31)
    {
        if (month == 12)
        {
            day = 1;
            month = 1;
            year++;
        }
        else
        {
            month++;
            day = 1;
        }
    }
    else
    {
        if (month == 2)
        {

            if (day == 28)
            {
                //闰年
                bool leap = is_leap_year(year);
                day++;
            }
            else
            {
                day = 1;
                month++;
            }
        }
        else
        {
            day++;
        }
    }

    cout << year;
    cout << '-';
    cout_(month);
    cout << '-';
    cout_(day);

    return 0;
}