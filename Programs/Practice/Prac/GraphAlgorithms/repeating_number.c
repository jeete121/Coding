#include <stdio.h>

int main()
{
    int arr[] = {2, 1, 3, 3, 4, 5, 4};

    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    int freq[maximum + 1];
    for (int i = 0; i <= maximum; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    printf("Repeating elements are\n");
    for (int i = 0; i <= maximum; i++)
    {
        if (freq[i] > 1)
        {
            printf("%d ", i);
        }
    }
    return 0;
}