#include <bits/stdc++.h>
using namespace std;

int luckBalance(int k, vector<vector<int>> contests)
{
    sort(contests.begin(), contests.end());

    int ans = 0;
    int n = contests.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (k > 0)
        {
            if (contests[i][1] == 1)
            {
                k--;
                ans += contests[i][0];
            }
            else
                ans += contests[i][0];
        }
        else
        {
            if (contests[i][1] == 1)
                ans -= contests[i][0];
            else
                ans += contests[i][0];
        }
    }
    return ans;
}
int main()
{
    int k = 3;
    vector<vector<int>> contests = {{5, 1}, {2, 1}, {1, 1},
                                    {8, 1}, {10, 0}, {5, 0}};

    cout << luckBalance(k, contests);
    return 0;
}
