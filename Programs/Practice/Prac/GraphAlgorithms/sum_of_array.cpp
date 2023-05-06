#include <stdio.h>

int main()
{
    int arr[] = {3, 4, 2, 5, 1, 6};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    printf("Sum of array elements is %d", sum);

    return 0;
}