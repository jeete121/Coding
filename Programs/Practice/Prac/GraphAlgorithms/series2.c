#include <stdio.h>
#include <math.h>

int main()
{
    int n, x;
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter value of x: ");
    scanf("%d", &x);

    float ans = n / (1 - x) - (x * (pow(x, n) - 1)) / (pow(x - 1, 2));

    printf("Sum of series is %f", ans);

    return 0;
}