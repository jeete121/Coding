#include <bits/stdc++.h>
using namespace std;

int main()
{
    int month = 3;
    int year = 2021;

    if (month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12)
    {
        cout << "31 Days\n";
    }
    else if (month == 2)
    {
        if (year % 100 == 0 && year % 400 == 0)
        {
            cout << "29 Days\n";
        }
        else if (year % 4 == 0 && year % 100 != 0)
        {
            cout << "29 Days\n";
        }
        else
        {
            cout << "28 Days\n";
        }
    }
    else
    {
        cout << "30 Days\n";
    }
    return 0;
}