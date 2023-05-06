#include <stdio.h>
int main()
{
    int n = 13;
    if (n <= 1)
        printf("Number is not prime ");
    else
    {
        int flag = 0;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("Number is prime ");
        }
        else
        {
            printf("Number is not prime ");
        }
    }
    return 0;
}