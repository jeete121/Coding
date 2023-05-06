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

//function to sort the array in descending
//order
void sortArrayDesc(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
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

    sortArrayDesc(arr2, n);

    int minimum = 0;
    for (int i = 0; i < n; i++)
    {
        minimum = minimum + arr1[i] * arr2[i];
    }

    printf("Minimum scalar product is: %d", minimum);
    return 0;
}