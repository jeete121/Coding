#include <stdio.h>

int main()
{
    int n = 18;

    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    if (sum > n)
    {
        printf("Abundant number\n");
    }
    else
    {
        printf("Not abundant number\n");
    }
    return 0;
}