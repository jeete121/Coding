#include <stdio.h>
#include <stdbool.h>

//function to check for disjoint arrays
bool disjointArray(int arr1[], int n, int arr2[], int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {6, 7, 8, 9};

    //find length of both the arrays
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    if (disjointArray(arr1, n, arr2, m))
    {
        printf("Arrays are disjoint\n");
    }
    else
    {
        printf("Arrays are not disjoint\n");
    }

    return 0;
}