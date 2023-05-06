#include <stdio.h>
int main()
{
    int i;
    int arr[] = {3, 4, 1, 5, 6, 2, 8, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    int maximum = arr[0];
    for (i = 1; i < len; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }
    printf("Maximum in array is %d", maximum);
    return 0;
}