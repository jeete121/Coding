#include <stdio.h>

int sumRec(int n)
{
    if (n == 1)
        return 1;
    return n + sumRec(n - 1);
}
int main()
{
    int n;

    printf("Enter a number : ");
    scanf("%d", &n);

    int sum = sumRec(n);
    printf("Sum of natural number till %d is %d", n, sum);

    return 0;
}