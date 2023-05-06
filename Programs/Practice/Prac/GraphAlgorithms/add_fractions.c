#include <stdio.h>

//function to find the gcd of two numbers
int gcdDenominators(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcdDenominators(b, a % b);
    }
}
int main()
{
    int numerator1, numerator2, denominator1, denominator2;

    printf("Enter numerator of first fraction: ");
    scanf("%d", &numerator1);

    printf("Enter denominator of first fraction: ");
    scanf("%d", &denominator1);

    printf("Enter numerator of second fraction : ");
    scanf("%d", &numerator2);

    printf("Enter deonminator of second fraction : ");
    scanf("%d", &denominator2);

    int gcd = gcdDenominators(denominator1, denominator2);

    int newNumerator = (numerator1 * denominator2 + numerator2 * denominator1) / gcd;

    int newDenominator = (denominator1 * denominator2) / gcd;

    printf("Added fractions numerator is %d\n", newNumerator);

    printf("Added fractions denominator is %d\n", newDenominator);

    return 0;
}