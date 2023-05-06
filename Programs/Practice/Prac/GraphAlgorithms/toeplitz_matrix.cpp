#include <bits/stdc++.h>
using namespace std;

bool isToeplitzMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return true;
    int m = matrix[0].size();

    int k = 0;
    while (true)
    {
        int i = 0, j = k;
        while (i < n && j < m)
        {
            if (matrix[i][j] != matrix[0][k])
                return false;
            i++;
            j++;
        }
        k++;
        if (k >= m)
            break;
    }

    k = 1;
    while (true)
    {
        int i = k;
        int j = 0;
        while (i < n && j < m)
        {
            if (matrix[i][j] != matrix[k][0])
                return false;
            i++;
            j++;
        }
        k++;
        if (k >= n)
            break;
    }
    return true;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 1, 2, 3},
                                  {9, 5, 1, 2}};

    if (isToeplitzMatrix(matrix))
        cout << "true";
    else
        cout << "false";

    return 0;
}