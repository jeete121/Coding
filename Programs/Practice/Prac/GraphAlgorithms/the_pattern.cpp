#include <bits/stdc++.h>
using namespace std;

void thePattern(vector<string> pattern, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (pattern[i][j] == '.' && pattern[i + 1][j] == '*')
                pattern[i + 1][j] = '*';
            else if (pattern[i][j] == '*' && pattern[i + 1][j] == '.')
                pattern[i + 1][j] = '.';
        }
    }

    for (int j = 0; j < m - 1; j++)
    {
        if (pattern[n - 1][j] == '.' && pattern[n - 1][j + 1] == '*')
            pattern[n - 1][j + 1] = '*';
        else if (pattern[n - 1][j] == '*' && pattern[n - 1][j + 1] == '.')
            pattern[n - 1][j + 1] = '.';
    }
    cout << pattern[n - 1][m - 1] << "\n";
}
int main()
{
    int n = 5, m = 5;

    vector<string> pattern = {{"*.***"},
                              {".**.."},
                              {".*.*."},
                              {"*...*"},
                              {"..*.*"}};

    thePattern(pattern, n, m);

    return 0;
}