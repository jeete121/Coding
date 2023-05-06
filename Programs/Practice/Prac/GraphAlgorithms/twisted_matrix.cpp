#include <bits/stdc++.h>
using namespace std;
int l;
void twistedMatrix(vector<vector<int>> &arr, int i, int j, int m, int n, vector<int> v)
{
    if (i >= m || j >= n)
        return;
    for (int p = i; p < n; p++)
        arr[i][p] = v[l++];
    for (int p = i + 1; p < m; p++)
        arr[p][n - 1] = v[l++];
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            arr[m - 1][p] = v[l++];
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            arr[p][j] = v[l++];
    twistedMatrix(arr, i + 1, j + 1, m - 1, n - 1, v);
}
int main()
{
    int n = 3;
    vector<vector<int>> arr = {{2, 5, 12},
                               {22, 45, 55},
                               {1, 6, 8}};
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            v.push_back(arr[i][j]);
        }
    }
    l = 0;
    sort(v.begin(), v.end());
    twistedMatrix(arr, 0, 0, n, n, v);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
    return 0;
}