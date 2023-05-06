#include <stdio.h>

int factRec(int n)
{
    if (n <= 1)
        return 1;
    return n * factRec(n - 1);
}
int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int fact = factRec(n);
    printf("Factorial is %d", fact);
    return 0;
}