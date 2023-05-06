#include <stdio.h>
#include <math.h>

int main()
{
    int arr[] = {3, 2, 4, 1, 3, 5};

    int n = sizeof(arr) / sizeof(arr[0]);
    if (n <= 1)
    {
        printf("Second small is not possible\n");
    }
    else
    {
        int firstSmall = __INT_MAX__, secondSmall = __INT_MAX__;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < firstSmall)
            {
                if (secondSmall > firstSmall)
                {
                    secondSmall = firstSmall;
                }
                firstSmall = arr[i];
            }
            else if (arr[i] < secondSmall)
            {
                secondSmall = arr[i];
            }
        }
        printf("Second small is %d", secondSmall);
    }
    return 0;
}