#include <stdio.h>

//function to multiply two maytrices
void multiplyMatrix(int arr[][3], int brr[][3], int n)
{
    //matrix which store the result
    int crr[3][3];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            crr[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                crr[i][j] += arr[i][k] * brr[k][j];
            }
        }
    }
    //store the final result back to
    //arr
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            arr[i][j] = crr[i][j];
    }
}
int main()
{
    //first matrix 3 X 3 matrix
    int arr[][3] = {{6, 2, 3}, {4, 3, 2}, {4, 5, 7}};
    //second matrix 3 X 3
    int brr[][3] = {{4, 6, 2}, {2, 6, 1}, {1, 5, 1}};
    int n = 3;
    multiplyMatrix(arr, brr, n);
    printf("Result after multiply is\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//Time Complexity: O(n^3)
//Space Complexity:O(n^2)