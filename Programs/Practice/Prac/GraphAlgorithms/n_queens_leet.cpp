#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans;

bool isValid(vector<string> &curr, int r, int c)
{
    for (int i = r; i >= 0; i--)
    {
        if (curr[i][c] == 'Q')
            return false;
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (curr[i][j] == 'Q')
            return false;
    }
    for (int i = r, j = c; i >= 0 && j < curr.size(); i--, j++)
    {
        if (curr[i][j] == 'Q')
            return false;
    }
    return true;
}

void dfs(vector<string> &curr, int r)
{
    if (curr.size() == r)
    {
        ans.push_back(curr);
        return;
    }
    for (int i = 0; i < curr.size(); i++)
    {
        if (isValid(curr, r, i))
        {
            curr[r][i] = 'Q';
            dfs(curr, r + 1);
            curr[r][i] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<string> curr(n, string(n, '.'));
    dfs(curr, 0);
    return ans;
}

int main()
{
    int n = 4;

    vector<vector<string>> queens = solveNQueens(n);

    cout << "[";
    for (int i = 0; i < queens.size(); i++)
    {
        cout << "[";
        for (int j = 0; j < queens[i].size(); j++)
        {
            cout << queens[i][j];
            if (j != queens[i].size() - 1)
                cout << ", ";
        }
        cout << "]";
        if (i != queens.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}