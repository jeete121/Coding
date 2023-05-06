#include <stdio.h>

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact = fact * i;
    return fact;
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += factorial(i);
    }
    printf("Sum of series is %d", sum);
    return 0;
}