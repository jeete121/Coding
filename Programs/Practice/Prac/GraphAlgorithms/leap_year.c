#include <stdio.h>
#include <stdbool.h>
//function to check given
//year is leap or not
bool isLeapYear(int year)
{
    //if year%100==0
    if (year % 100 == 0)
    {
        //if year%400==0
        if (year % 400 == 0)
            return true;
        else
            return false;
    }
    //if year%4!=0
    if (year % 4 != 0)
        return false;
    else
        return true;
}
int main()
{
    int year = 2020;
    if (isLeapYear(year))
    {
        printf("Leap Year\n");
    }
    else
    {
        printf("Not a Leap Year\n");
    }
    return 0;
}