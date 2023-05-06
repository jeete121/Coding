#include <stdio.h>
int main()
{
    int divident, divisor;
    int quotient, remainder;

    printf("Enter divident value : ");
    scanf("%d", &divident);

    printf("Enter divisor value : ");
    scanf("%d", &divisor);

    quotient = divident / divisor;
    remainder = divident % divisor;

    printf("Quotient is %d\n", quotient);
    printf("Remainder is %d\n", remainder);

    return 0;
}