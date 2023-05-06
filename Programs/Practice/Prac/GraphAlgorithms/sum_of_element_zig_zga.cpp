#include <bits/stdc++.h>
using namespace std;

int sumMatrixZigZag(vector<vector<int>> &matrix)
{

    int sum = 0;
    int i = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    int k = n - 1;

    //sum of first and last row
    for (int j = 0; j < m; j++)
    {
        sum += matrix[i][j];
        sum += matrix[k][j];
    }

    int diagonalSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i + j) == n - 1)
            {
                diagonalSum += matrix[i][j];
            }
        }
    }
    diagonalSum = diagonalSum - matrix[0][m - 1];
    diagonalSum = diagonalSum - matrix[n - 1][0];
    sum += diagonalSum;
    return sum;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    cout << sumMatrixZigZag(matrix);

    return 0;
}