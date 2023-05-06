#include <stdio.h>
int main()
{
    int arr[] = {2, 3, 5, 1, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Size of array is %d", len);
    return 0;
}