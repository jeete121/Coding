#include <stdio.h>
int main()
{
    int arr[] = {4, 5, 3, 2, 6, 7};

    //find the lenth of array
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;

    //find sum of array
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    float mean = (float)sum / n;
    printf("Mean of array is %f", mean);
}