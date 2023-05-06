#include <stdio.h>
int main()
{
    int arr1[] = {1, 3, 4};
    int arr2[] = {2, 6, 8};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    int m = sizeof(arr2) / sizeof(arr2[0]);

    int sortedArray[n + m];
    int i = 0, j = 0;
    int l = 0;
    while (i < n || j < m)
    {
        if (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                sortedArray[l] = arr1[i];
                i++;
                l++;
            }
            else
            {
                sortedArray[l] = arr2[j];
                j++;
                l++;
            }
        }
        else if (i == n)
        {
            sortedArray[l] = arr2[j];
            l++;
            j++;
        }
        else
        {
            sortedArray[l] = arr1[i];
            i++;
            l++;
        }
    }
    printf("Sorted array after merge is\n");
    for (i = 0; i < l; i++)
    {
        printf("%d ", sortedArray[i]);
    }
    return 0;
}