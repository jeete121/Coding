#include <bits/stdc++.h>
using namespace std;

bool isSymmetric(vector<vector<int>> matrix)
{
    //squae matrix
    int n = matrix.size();

    int transpose[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (transpose[i][j] != matrix[i][j])
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    //square matrix
    vector<vector<int>> matrix = {{1, 7, 3},
                                  {7, 4, -5},
                                  {3, -5, 6}};

    if (isSymmetric(matrix))
        cout << "Symmetric\n";
    else
        cout << "Not Symmetric\n";

    return 0;
}