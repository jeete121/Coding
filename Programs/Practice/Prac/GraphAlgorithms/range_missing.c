#include <stdio.h>

int main()
{
    int arr[] = {1, 2, 5, 7, 8, 9};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start, end;
    printf("Enter starting number of range : ");
    scanf("%d", &start);

    printf("Enter ending number of range : ");
    scanf("%d", &end);

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
    printf("Missing numbers in the range %d to %d are:\n", start, end);

    for (int i = start; i <= end; i++)
    {
        if (freq[i] == 0)
        {
            printf("%d ", i);
        }
    }
    return 0;
}