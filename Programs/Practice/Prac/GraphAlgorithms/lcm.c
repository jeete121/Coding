#include <stdio.h>

int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
int main()
{
    int a = 10, b = 24;
    int gcd = GCD(a, b);
    int lcm = a * b / gcd;
    printf("LCM is %d", lcm);
    return 0;
}