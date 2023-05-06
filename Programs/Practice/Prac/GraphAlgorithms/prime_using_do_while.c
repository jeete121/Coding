#include <stdio.h>
int main()
{
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    if (num <= 1)
    {
        printf("Number is not a prime\n");
    }
    else
    {
        int i = 2;
        if (num == 2)
        {
            printf("Number is prime ");
        }
        else
        {
            int flag = 0;
            do
            {
                if (num % i == 0)
                {
                    flag = 1;
                    break;
                }
                i++;
            } while (i < num);
            if (flag == 0)
            {
                printf("Number is prime ");
            }
            else
            {
                printf("Number is not a prime ");
            }
        }
    }

    return 0;
}