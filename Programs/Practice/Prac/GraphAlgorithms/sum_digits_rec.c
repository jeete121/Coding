#include <stdio.h>

int sumDigits(int n)
{
    if (n < 10)
        return n;
    return n % 10 + sumDigits(n / 10);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int sum = sumDigits(n);
    printf("Sum of digits is %d", sum);
    return 0;
}