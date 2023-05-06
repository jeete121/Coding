#include <stdio.h>

int main()
{
    int arr1[] = {1, 3, 5, 2, 4};
    int arr2[] = {2, 4, 6, 1, 3};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr1[i] == arr2[j] && arr1[j] == arr2[i])
            {
                printf("(%d,%d)\n", arr1[i], arr1[j]);
            }
        }
    }
    return 0;
}