#include <stdio.h>
int main()
{
    int n = 300;

    printf("Prime numbers are ");
    for (int i = 1; i <= n; i++)
    {
        if (i > 1)
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
                printf("%d ", i);
        }
    }
    return 0;
}