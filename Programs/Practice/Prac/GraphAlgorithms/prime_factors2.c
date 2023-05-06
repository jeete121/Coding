#include <stdio.h>
int main()
{
    int num = 24;
    //if number is divisible by 2
    while (num % 2 == 0)
    {
        printf("%d ", 2);
        num = num / 2;
    }
    //now iterate from i=3 and skip all
    //even number
    for (int i = 3; i * i <= num; i += 2)
    {
        while (num % i == 0)
        {
            printf("%d ", i);
            num = num / i;
        }
    }
    if (num > 1)
    {
        printf("%d ", num);
    }
    return 0;
}