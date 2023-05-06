#include <stdio.h>
int main()
{
    int arr[] = {4, 3, 5, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}