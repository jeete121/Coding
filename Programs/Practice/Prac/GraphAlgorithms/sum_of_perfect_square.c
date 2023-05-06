#include <stdio.h>
#include <math.h>

int main()
{

    int arr[] = {1, 4, 3, 7, 8, 9, 16, 45, 25};

    int n = sizeof(arr) / sizeof(arr[0]);

    int sumPerfectSquare = 0;
    for (int i = 0; i < n; i++)
    {
        if (sqrt(arr[i]) == (int)sqrt(arr[i]))
        {
            sumPerfectSquare = sumPerfectSquare + arr[i];
        }
    }

    printf("Sum of perfect squere numbers of array is %d", sumPerfectSquare);

    return 0;
}