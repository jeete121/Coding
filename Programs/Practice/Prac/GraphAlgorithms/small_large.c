#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[] = {3, 2, 4, 5, 1, 6, 3};

    int n = sizeof(arr) / sizeof(arr[0]);

    int large = INT_MIN;
    int small = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > large)
        {
            large = arr[i];
        }
        if (arr[i] < small)
        {
            small = arr[i];
        }
    }
    printf("Smallest Number is %d\n", small);
    printf("Largest number is %d\n", large);

    return 0;
}