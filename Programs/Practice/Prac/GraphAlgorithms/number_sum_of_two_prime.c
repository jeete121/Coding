#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if (n == 1)
    {
        return false;
    }
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int flag = 0;
    for (int i = 2; i < num; i++)
    {
        if (isPrime(i) && isPrime(num - i))
        {

            printf("Number is expressed as sum of two primes\n");
            printf("%d + %d = %d", i, num - i, num);

            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Number is not expressed as sum of two primes\n");
    }

    return 0;
}