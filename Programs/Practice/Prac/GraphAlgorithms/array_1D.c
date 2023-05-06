#include <stdio.h>

int main()
{

    int arr[] = {16, 13, 7, 2, 1, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    printf("%d", sum);
    return 0;
}
