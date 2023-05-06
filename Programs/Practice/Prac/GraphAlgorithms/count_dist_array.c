#include <stdio.h>

int main()
{
    int arr[] = {3, 4, 5, 3, 4, 2, 1};

    //find the length of array
    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum = 0;

    //find the maximum of the array
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
    //find the frequency of each elements
    //in the array
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int count = 0;
    for (int i = 0; i <= maximum; i++)
    {
        if (freq[i] > 0)
        {
            count++;
        }
    }
    printf("Count of Distinct elements is %d", count);
    return 0;
}