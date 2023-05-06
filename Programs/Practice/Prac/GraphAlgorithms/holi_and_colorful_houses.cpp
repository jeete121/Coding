#include <bits/stdc++.h>
using namespace std;

void colourfulHouses(string s, int n, int q, vector<vector<int>> &queries)
{
    for (int i = 0; i < q; i++)
    {
        int l = queries[i][0], r = queries[i][1];

        if (l < r)
        {
            l = l - 1;
            r = r - 1;
            int cnt = 0, ans = INT_MAX;
            for (int i = l; i < r; i++)
                if (s[i] != s[i + 1])
                    cnt++;
            ans = min(ans, cnt);
            cnt = 0;
            for (int i = l; i > 0; i--)
                if (s[i] != s[i - 1])
                    cnt++;
            if (s[0] != s[n - 1])
                cnt++;
            for (int i = n - 2; i >= r; i--)
                if (s[i] != s[i + 1])
                    cnt++;
            ans = min(ans, cnt);
            cout << ans << "\n";
        }
        else
        {
            l = l - 1;
            r = r - 1;
            int cnt = 0, ans1 = INT_MAX;
            for (int i = l; i > r; i--)
                if (s[i] != s[i - 1])
                    cnt++;
            ans1 = min(ans1, cnt);
            cnt = 0;
            for (int i = l; i < n - 1; i++)
                if (s[i] != s[i + 1])
                    cnt++;
            if (s[0] != s[n - 1])
                cnt++;
            for (int i = 0; i < r; i++)
                if (s[i] != s[i + 1])
                    cnt++;
            ans1 = min(ans1, cnt);
            cout << ans1 << "\n";
        }
    }
}
int main()
{

    int n = 5, q = 2;

    string s = "RRRGG";

    vector<vector<int>> queries = {{1, 5}, {3, 2}};

    colourfulHouses(s, n, q, queries);

    return 0;
}