#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

bool isArmstrong(int n)
{
    int sum = 0, num = n;
    while (num > 0)
    {
        int temp = num % 10;
        sum = sum + pow(temp, 3);
        num = num / 10;
    }
    if (sum == n)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d", &n);

    if (isPrime(n))
    {
        printf("Number is Prime\n");
    }
    else
    {
        printf("Number is not Prime\n");
    }
    if (isArmstrong(n))
    {
        printf("Number is Armstrong\n");
    }
    else
    {
        printf("Number is not Armstrong\n");
    }
    return 0;
}