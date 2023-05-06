#include <stdio.h>
int main()
{
    int num;

    printf("Enter a number : ");
    scanf("%d", &num);

    int numDigits = 0;
    while (num > 0)
    {
        numDigits++;
        num = num / 10;
    }
    printf("Number of digits are %d ", numDigits);

    return 0;
}