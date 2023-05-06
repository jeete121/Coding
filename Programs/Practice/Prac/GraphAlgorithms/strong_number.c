#include <stdio.h>
#include <stdbool.h>

int fact(int n)
{
    if (n == 1 || n == 0)
        return 1;
    return n * fact(n - 1);
}
//function to check for
//strong number
bool isStrong(int num)
{
    int temp = num;
    int sum = 0;
    while (num > 0)
    {
        sum += fact(num % 10);
        num = num / 10;
    }
    if (temp == sum)
        return true;
    return false;
}
int main()
{
    int num = 145;
    if (isStrong(num))
    {
        printf("Number is strong ");
    }
    else
    {
        printf("Not a strong number ");
    }
    return 0;
}