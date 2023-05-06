#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n, i;
    int factorial = 1;
    n = atoi(argv[1]);
    for (i = 1; i <= n; ++i)
    {
        factorial = factorial * i;
    }
    printf("Factorial is %d", factorial);
}