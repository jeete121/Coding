#include <stdio.h>

void sortArray(int arr[], int n)
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
    int arr[] = {3, 4, 5, 6, 7, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    sortArray(arr, n);
    if (n % 2 == 0)
    {
        float median = (float)(arr[n / 2] + arr[n / 2 - 1]) / 2;
        printf("Median is %f ", median);
    }
    else
    {
        float median = (float)(arr[n / 2]);
        printf("Median is %f ", median);
    }
    return 0;
}