#include <stdio.h>

int main()
{
    int arr[] = {2, 2, 2, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[0])
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("All elements of array are equal\n");
    }
    else
    {
        printf("All elements of array are not equal\n");
    }
    return 0;
}