#include <bits/stdc++.h>
using namespace std;

bool isValid(int x, int y, int n, int m)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
vector<vector<int>> imageSmoother(vector<vector<int>> &M)
{
    int n = M.size();
    if (n == 0)
        return M;
    int m = M[0].size();
    vector<vector<int>> res(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int cnt = 0, sum = 0;
            for (int k = 0; k < 8; k++)
            {
                if (isValid(i + dx[k], j + dy[k], n, m))
                {
                    sum += M[i + dx[k]][j + dy[k]];
                    cnt++;
                }
            }
            cnt++;
            sum += M[i][j];

            res[i][j] = sum / cnt;
            cnt = 0;
        }
    }

    return res;
}

int main()
{
    vector<vector<int>> M = {{1, 1, 1},
                             {1, 0, 1},
                             {1, 1, 1}};
    M = imageSmoother(M);
    for (int i = 0; i < M.size(); i++)
    {
        for (int j = 0; j < M[i].size(); j++)
        {
            cout << M[i][j] << " ";
        }
        cout << "\n";
    }
}
