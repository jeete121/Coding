#include <bits/stdc++.h>
using namespace std;

string gridChallenge(vector<string> grid)
{

    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        sort(grid[i].begin(), grid[i].end());
    }
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
            arr[i][j] = grid[i][j];
    }
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = 1; i < n; i++)
        {
            if (arr[i][j] < arr[i - 1][j])
            {
                flag = 1;
                break;
            }
        }
    }
    if (flag == 0)
        return "YES";
    else
        return "NO";
}
int main()
{

    vector<string> grid = {"ebacd", "fghij", "olmkn", 
                           "trpqs", "xywuv"};

    cout << gridChallenge(grid);

    return 0;
}