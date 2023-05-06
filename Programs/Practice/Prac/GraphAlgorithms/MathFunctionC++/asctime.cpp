#include <bits/stdc++.h>
using namespace std;

int main()
{

    time_t rawtime;
    struct tm *timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    cout << asctime(timeinfo) << "\n";

    return 0;
}
/*

The returned string has the following format:

Www Mmm dd hh:mm:ss yyyy

Where Www is the weekday, Mmm the month (in letters), 
dd the day of the month, hh:mm:ss the time, and yyyy the year.
File: time.h
*/