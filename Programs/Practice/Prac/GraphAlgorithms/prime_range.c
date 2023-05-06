#include <stdio.h>

void primeRange(int start, int end)
{

    for (int i = start; i <= end; i++)
    {
        if (i == 1)
        {
            continue;
        }
        else
        {
            int flag = 0;
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("%d ", i);
            }
        }
    }
}
int main()
{
    int start, end;

    printf("Enter starting number : ");
    scanf("%d", &start);

    printf("Enter ending number : ");
    scanf("%d", &end);

    printf("Prime number in range %d to %d are:\n", start, end);
    primeRange(start, end);

    return 0;
}