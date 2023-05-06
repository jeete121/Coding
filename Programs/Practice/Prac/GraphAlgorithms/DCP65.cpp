#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> v;
    int m = matrix.size();
    if (m == 0)
        return v;
    int n = matrix[0].size();
    int i;

    int l = 0, k = 0;
    while (k < m && l < n)
    {
        //first row from remaining
        for (i = l; i < n; i++)
            v.push_back(matrix[k][i]);
        k++;
        //last col from remaining
        for (i = k; i < m; i++)
            v.push_back(matrix[i][n - 1]);
        n--;
        // last row from remaining
        if (k < m)
        {
            for (i = n - 1; i >= l; i--)
                v.push_back(matrix[m - 1][i]);
            m--;
        }
        //first col from remaining
        if (l < n)
        {
            for (i = m - 1; i >= k; i--)
                v.push_back(matrix[i][l]);
            l++;
        }
    }
    return v;
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {6, 7, 8, 9, 10},
                                  {11, 12, 13, 14, 15},
                                  {16, 17, 18, 19, 20}};

    vector<int> spiral = spiralOrder(matrix);

    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
    }
    return 0;
}