#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "haveaniceday";
    int n = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != ' ')
        {
            n++;
        }
    }
    int row = sqrt(n);
    int col = row + 1;
    if (row * row == n)
        col = row;
    while (row * col < n)
    {
        if (row < col)
            row++;
        else
            col++;
        if (row * col >= n)
            break;
    }

    int l = 0;
    char grid[row][col];
    vector<string> v;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            while (l < n && s[l] == ' ')
                l++;
            if (l != n)
                grid[i][j] = s[l++];
            else
                grid[i][j] = '-';
        }
    }
    for (int i = 0; i < col; i++)
    {
        string str = "";
        for (int j = 0; j < row; j++)
        {
            if (grid[j][i] != '-')
                str += grid[j][i];
        }
        v.push_back(str);
    }
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    return 0;
}
