#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << "\n";
    }
}

void rubiksSquare(int n, int r, int c,
                  vector<vector<int>> &arr,
                  vector<int> &row,
                  vector<int> &col)
{
    for (int i = 0; i < r; i++)
    {
        int x = row[i];

        int temp = arr[x - 1][n - 1];
        for (int k = n - 2; k >= 0; k--)
        {
            arr[x - 1][k + 1] = arr[x - 1][k];
        }

        arr[x - 1][0] = temp;
    }

    for (int i = 0; i < c; i++)
    {
        int x = col[i];

        int temp = arr[n - 1][x - 1];
        for (int k = n - 2; k >= 0; k--)
        {
            arr[k + 1][x - 1] = arr[k][x - 1];
        }
        arr[0][x - 1] = temp;
    }

    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(arr[i][j]);
        }
        res.push_back(v);
    }
    print(res);
}
int main()
{
    int n = 5, r = 3, c = 4;

    vector<vector<int>> arr = {{8, 6, 3, 9, 1},
                               {7, 4, 6, 4, 6},
                               {3, 4, 2, 0, 4},
                               {0, 5, 3, 3, 9},
                               {8, 5, 4, 9, 3}};

    vector<int> row = {5, 2, 1};

    vector<int> col = {4, 5, 5, 4};

    rubiksSquare(n, r, c, arr, row, col);

    return 0;
}