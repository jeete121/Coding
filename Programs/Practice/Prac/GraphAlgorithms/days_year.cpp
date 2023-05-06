#include <bits/stdc++.h>
using namespace std;

//function to find the years
int yearConvert(int days)
{
    //years 
    int year=days/365;
    return year;
}
int weekConvert(int days)
{
    int year=days/365;
    //remaning days after year
    int rDays=days-year*365;
    //calcuate weeks
    int week=rDays/7;
    return week;
}
int dayConvert(int days)
{
    int year=days/365;
    int rDays=days-year*365;
    int week=rDays/7;
    //remaing days after year and weeks
    rDays=rDays-week*7;
    return rDays;
}
int main()
{
    int days=1320;
    int year=yearConvert(days);
    int weeks=weekConvert(days);
    int day=dayConvert(days);
    cout<<"Years "<<year<<"\n";
    cout<<"Weeks "<<weeks<<"\n";
    cout<<"Days "<<day<<"\n";
    return 0;
}