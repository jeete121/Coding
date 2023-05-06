#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix)
{
    int rowLen = matrix.size();
    if (rowLen == 0)
    {
        return 0;
    }
    int colLen = matrix[0].size();
    if (colLen == 0)
    {
        return 0;
    }

    vector<vector<int>> dpMatrix(rowLen, vector<int>(colLen, 0));

    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            dpMatrix[i][j] = matrix[i][j] == '1' ? 1 : 0;
        }
    }

    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 1; j < colLen; j++)
        {
            if (dpMatrix[i][j] == 0)
            {
                continue;
            }

            dpMatrix[i][j] = dpMatrix[i][j - 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            int length = INT_MAX;
            for (int k = i; k >= 0 && dpMatrix[k][j] != 0; k--)
            {
                length = min(length, dpMatrix[k][j]);
                int breadth = (i - k + 1);
                ans = max(ans, length * breadth);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalRectangle(matrix);

    return 0;
}