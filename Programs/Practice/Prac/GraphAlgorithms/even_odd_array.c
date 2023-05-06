#include <stdio.h>

int main()
{
    int arr[] = {3, 2, 4, 1, 5, 6, 8};

    int n = sizeof(arr) / sizeof(arr[0]);

    int even = 0, odd = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }
    printf("Even numbers count is %d\n", even);
    printf("Odd numbers count is %d\n", odd);

    return 0;
}