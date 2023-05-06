#include <stdio.h>

//function to sort the array in ascending
//order
void sortArrayAsc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr1[] = {2, 4, 3};
    int arr2[] = {4, 6, 2};

    int n = sizeof(arr1) / sizeof(arr1[0]);
    sortArrayAsc(arr1, n);

    sortArrayAsc(arr2, n);

    int maximum = 0;
    for (int i = 0; i < n; i++)
    {
        maximum = maximum + arr1[i] * arr2[i];
    }

    printf("Maximum scalar product is: %d", maximum);
    return 0;
}