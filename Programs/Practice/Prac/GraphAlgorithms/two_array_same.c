#include <stdio.h>

int main()
{
    int arr1[] = {2, 3, 4, 1, 5};

    int arr2[] = {2, 3, 4, 1, 5};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    if (n != m)
    {
        printf("Both arrays are different\n");
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr1[i] != arr2[i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("Both arrays are same\n");
        }
        else
        {
            printf("Both arrays are different\n");
        }
    }

    return 0;
}