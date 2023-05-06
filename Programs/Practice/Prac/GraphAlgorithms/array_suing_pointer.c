#include <stdio.h>
int main()
{
    int arr[] = {3, 2, 4, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Array elemets are:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(arr + i));
    }
    return 0;
}