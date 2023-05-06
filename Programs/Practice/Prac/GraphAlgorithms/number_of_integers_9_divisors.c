#include <stdio.h>

int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);
    int diviorsCount = 0;
    for (int i = 1; i <= n; i++)
    {
        int count = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0)
            {
                count++;
            }
        }
        if (count == 9)
        {
            diviorsCount++;
        }
    }
    printf("Number of integers with exactly 9 divisors til %d is %d", n, diviorsCount);

    return 0;
}