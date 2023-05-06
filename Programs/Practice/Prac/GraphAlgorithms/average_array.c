#include <stdio.h>
int main()
{
    int n;
    printf("Number of elements: ");
    scanf("%d", &n);
    float arr[n];
    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &arr[i]);
    }
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }
    float average = sum / n;
    printf("Average of array numbers is %f", average);
    return 0;
}