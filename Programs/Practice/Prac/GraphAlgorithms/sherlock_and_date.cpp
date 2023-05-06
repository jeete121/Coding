#include <bits/stdc++.h>
using namespace std;

bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

void sherlockAndDate(int day, int year, string m)
{

    if (day == 1 && m == "January")
    {
        cout << 31 << " "
             << "December " << year - 1 << "\n";
    }
    else if (day == 1 && m == "February")
        cout << 31 << " "
             << "January " << year << "\n";
    else if (day == 1 && m == "March")
    {
        if (checkYear(year) == true)
            cout << 29 << " February " << year << "\n";
        else
            cout << 28 << " February " << year << "\n";
    }
    else if (day == 1 && m == "April")
        cout << 31 << " March " << year << "\n";
    else if (day == 1 && m == "May")
        cout << 30 << " April " << year << "\n";
    else if (day == 1 && m == "June")
        cout << 31 << " May " << year << "\n";
    else if (day == 1 && m == "July")
        cout << 30 << " June " << year << "\n";
    else if (day == 1 && m == "August")
        cout << 31 << " July " << year << "\n";
    else if (day == 1 && m == "September")
        cout << 31 << " August " << year << "\n";
    else if (day == 1 && m == "October")
        cout << 30 << " September " << year << "\n";
    else if (day == 1 && m == "November")
        cout << 31 << " October " << year << "\n";
    else if (day == 1 && m == "December")
        cout << 30 << " November " << year << "\n";
    else
        cout << day - 1 << " " << m << " " << year << "\n";
}
int main()
{

    int day = 23, year = 1914;
    string m = "July";

    sherlockAndDate(day, year, m);

    return 0;
}