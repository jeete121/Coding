#include <stdio.h>

int main()
{
    int num = 156;
    int n = num;
    int sumDigits = 0;
    while (n > 0)
    {
        int temp = n % 10;
        sumDigits = sumDigits + temp;
        n = n / 10;
    }
    if (num % sumDigits == 0)
    {
        printf("Harshad Number\n");
    }
    else
    {
        printf("Not a Harshad Number\n");
    }
    return 0;
}