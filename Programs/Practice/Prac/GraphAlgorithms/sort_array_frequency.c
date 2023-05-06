#include <stdio.h>

int main()
{
    int arr[] = {3, 3, 4, 2, 3, 4, 5, 2, 3};

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

    printf("Sorted array according to frequency\n");
    for (int i = 0; i <= maximum; i++)
    {
        int max1 = __INT_MAX__;
        int j, index = -1;
        for (j = 0; j <= maximum; j++)
        {
            if (freq[j] > 0 && freq[j] < max1)
            {
                max1 = freq[j];
                index = j;
            }
        }
        if (index == -1)
        {
            break;
        }
        else
        {
            while (freq[index]--)
            {
                printf("%d ", index);
            }
        }
    }

    return 0;
}