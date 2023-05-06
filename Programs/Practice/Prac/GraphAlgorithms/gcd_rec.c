#include <stdio.h>

int gcdRec(int a, int b)
{
    if (b == 0)
        return a;
    return gcdRec(b, a % b);
}
int main()
{
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    int gcd = gcdRec(a, b);
    printf("GCD of numbers is %d ", gcd);
    return 0;
}