#include <stdio.h>

int sumFibSeries(int n)
{
    int a = 0, b = 1;
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    else
    {
        int sum = 1;
        for (int i = 2; i < n; i++)
        {
            int temp = b;
            int fib = a + b;
            b = a + b;
            a = temp;
            sum += fib;
        }
        return sum;
    }
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int sum = sumFibSeries(n);
    printf("Sum of series of length %d is %d ", n, sum);
    return 0;
}