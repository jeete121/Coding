#include <stdio.h>
int main()
{
    int arr[] = {3, 3, 4, 3, 5, 5, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maximum = -1;
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
    int sum = 0;
    for (int i = 0; i <= maximum; i++)
    {
        if (freq[i] % 2 == 1)
        {
            sum += i;
        }
    }
    printf("Sum of odd frequency numbers is %d ", sum);
    return 0;
}