#include <stdio.h>
#include <math.h>

int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    int n, x;
    printf("Enter value of n: ");
    scanf("%d", &n);

    printf("Enter value of x: ");
    scanf("%d", &x);

    float sum = 0;
    for (int i = 0; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            sum = sum + pow(x, i) / fact(i);
        }
        else
        {
            sum = sum - pow(x, i) / fact(i);
        }
    }
    printf("%f", sum);
    return 0;
}