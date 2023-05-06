#include <bits/stdc++.h>
using namespace std;

int maximumBoarders(int n, int m, char arr[][1000])
{

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int cu = 0, boru1 = 0, boru2 = 0;
        for (int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (arr[i][j] == '#')
                {
                    boru1++;
                    continue;
                }
            }
            if (arr[i][j] != '.')
            {
                if (cu == 0)
                {
                    if (arr[i][j] != arr[i - 1][j])
                        boru1++;
                    else
                    {
                        cu++;
                    }
                }
                else
                {
                    if (arr[i][j] != arr[i - 1][j])
                        boru2++;
                    else
                        cu++;
                }
            }
        }
        //update the ans
        ans = max(ans, max(boru1, boru2));
    }

    for (int i = 0; i < n; i++)
    {
        int cd = 0, bord1 = 0, bord2 = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != '.')
            {
                if (cd == 0)
                {
                    if (arr[i][j] != arr[i + 1][j])
                        bord1++;
                    else
                    {
                        cd++;
                    }
                }
                else
                {
                    if (arr[i][j] != arr[i + 1][j])
                        bord2++;
                }
            }
        }
        //update the ans
        ans = max(ans, max(bord1, bord2));
    }
    return ans;
}
int main()
{

    int n = 2, m = 15;
    char arr[1000][1000] = {".....####......",
                            ".....#........."};

    cout << maximumBoarders(n, m, arr) << "\n";

    return 0;
}