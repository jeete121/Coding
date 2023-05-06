#include <bits/stdc++.h>
using namespace std;

//function to find the sum of 
//matrix of the square matrix
int diagonalSum(vector<vector<int>> &matrix) 
{
    int sum = 0;

    int n = matrix.size();
    for (int i = 0; i < n; i++) 
      {
         for (int j = 0; j < n; j++) 
            {
                if (i == j) {
                    sum += matrix[i][j];
                    if (j != n - 1 - j) {
                        sum += matrix[i][n - 1 - j];
                    }
                }
            }
        }
     return sum;
}

int main()
{
    // given input matrix as square
    // matrix
   vector<vector<int>> matrix = { { 1, 1, 1, 1 }, { 1, 1, 1, 1 },
                 { 1, 1, 1, 1 }, { 1, 1, 1, 1 } };
     int sum = diagonalSum(matrix);
     cout<<sum<<"\n";
     return 0;
}

