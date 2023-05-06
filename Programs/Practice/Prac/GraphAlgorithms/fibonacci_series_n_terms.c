#include <stdio.h>
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int a = 0, b = 1;
    int cnt = 0;
    printf("Fibonacci Series is: ");
    if (n == 1)
        printf("%d", a);
    else if (n == 2)
        printf("%d %d", a, b);
    else
    {
        printf("%d ", a);
        printf("%d ", b);
        for (int i = 2; i < n; i++)
        {
            int fib = a + b;
            int temp = b;
            b = a + b;
            a = temp;
            printf("%d ", fib);
        }
    }
    return 0;
}