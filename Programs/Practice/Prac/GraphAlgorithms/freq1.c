#include <stdio.h>
#include <limits.h>

int main()
{
    int arr[] = {3, 2, 4, 5, 3, 1, 5};

    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum = INT_MIN;
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

    //find the frequecy of each elements
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }
    for (int i = 0; i <= maximum; i++)
    {
        if (freq[i] > 0)
        {
            printf("Frequecy of %d is %d\n", i, freq[i]);
        }
    }
    return 0;
}