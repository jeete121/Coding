#include <bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();

    int m = matrix[0].size();

    int temp[m];

    //update k into the matrix size
    k = k % m;

    for (int i = 0; i < n; i++)
    {

        for (int t = 0; t < m - k; t++)
        {
            temp[t] = matrix[i][t];
        }

        for (int j = m - k; j < m; j++)
        {
            matrix[i][j - m + k] = matrix[i][j];
        }

        // copy elements from temporary array to end of
        //the  matrix
        for (int j = k; j < m; j++)
        {
            matrix[i][j] = temp[j - k];
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{12, 23, 34},
                                  {45, 56, 67},
                                  {78, 89, 91}};
    int k = 2;

    rotateMatrix(matrix, k);
    cout << "[";
    for (int i = 0; i < matrix.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j];
            if (j != matrix[i].size() - 1)
                cout << ",";
        }
        cout << "]";
        if (i != matrix.size() - 1)
            cout << ",";
    }
    cout << "]";
    return 0;
}