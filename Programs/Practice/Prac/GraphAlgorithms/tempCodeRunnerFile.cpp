#include <bits/stdc++.h>
using namespace std;

int maximumBoarders(int n, int m, char arr[][1000])
{

    int cd, bord1, bord2;
    int cu, boru1, boru2;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        cu = 0, boru1 = 0, boru2 = 0;
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
        ans = max(ans, max(boru1, boru2));
    }

    for (int i = 0; i < n; i++)
    {
        cd = 0, bord1 = 0, bord2 = 0;
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
        ans = max(ans, max(bord1, bord2));
    }
    return ans;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        char arr[1000][1000];

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        cout << maximumBoarders(n, m, arr) << "\n";
    }
}