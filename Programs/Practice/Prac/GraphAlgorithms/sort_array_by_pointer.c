#include <stdio.h>

void sortArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (*(arr + j) > *(arr + j + 1))
            {
                char temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}
int main()
{
    int arr[] = {3, 2, 1, 4, 7, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortArray(arr, n);
    printf("Array after sort is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}