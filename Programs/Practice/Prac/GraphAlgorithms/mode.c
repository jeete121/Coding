#include <stdio.h>
int main()
{
    int arr[] = {3, 4, 5, 3, 4, 3, 3};

    //find the length of array
    int n = sizeof(arr) / sizeof(arr[0]);

    int maximum = 0;

    //find the maximum in the array
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    int freq[maximum + 1];

    //set frequecy of maximum value size
    //as 0
    for (int i = 0; i <= maximum; i++)
    {
        freq[i] = 0;
    }

    //calculate the frequency of each
    //elements in the array
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    int mode = -1;
    int maxFreq = 0;
    for (int i = 0; i <= maximum; i++)
    {
        if (freq[i] > maxFreq)
        {
            mode = i;
            maxFreq = freq[i];
        }
    }

    printf("Mode of the array is %d", mode);
    return 0;
}