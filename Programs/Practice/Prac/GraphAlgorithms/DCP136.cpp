#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<int>> &matrix)
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

    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 1; j < colLen; j++)
        {
            if (matrix[i][j] == 0)
            {
                continue;
            }

            matrix[i][j] = matrix[i][j - 1] + 1;
        }
    }

    int ans = 0;
    for (int i = 0; i < rowLen; i++)
    {
        for (int j = 0; j < colLen; j++)
        {
            int length = INT_MAX;
            for (int k = i; k >= 0 && matrix[k][j] != 0; k--)
            {
                length = min(length, matrix[k][j]);
                int breadth = (i - k + 1);
                ans = max(ans, length * breadth);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 0, 1, 1},
                                  {1, 0, 1, 1},
                                  {0, 1, 0, 0}};
    cout << maximalRectangle(matrix);

    return 0;
}