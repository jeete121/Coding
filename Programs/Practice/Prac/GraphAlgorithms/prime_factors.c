#include <stdio.h>
int main()
{
    int num = 24;
    for (int i = 2; i * i <= num; i++)
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