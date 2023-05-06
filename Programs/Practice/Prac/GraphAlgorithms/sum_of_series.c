#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int facti = 1;
        for (int j = 1; j <= i; j++)
        {
            facti = facti * j;
        }
        sum += facti;
    }

    printf("Sum of series is %d", sum);
    return 0;
}