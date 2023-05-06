#include <stdio.h>
int main()
{
    int arr[] = {3, -2, 4, -4, 5, -6, -7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int positive[n];
    int negative[n];
    int zeronum[n];
    int zero = 0, pos = 0, neg = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            positive[pos] = arr[i];
            pos++;
        }
        else if (arr[i] < 0)
        {
            negative[neg] = arr[i];
            neg++;
        }
        else
        {
            zeronum[zero] = arr[i];
            zero++;
        }
    }
    printf("Array after rearrange is\n");
    for (int i = 0; i < neg; i++)
    {
        printf("%d ", negative[i]);
    }
    for (int i = 0; i < zero; i++)
    {
        printf("%d ", zeronum[i]);
    }
    for (int i = 0; i < pos; i++)
    {
        printf("%d ", positive[i]);
    }
}