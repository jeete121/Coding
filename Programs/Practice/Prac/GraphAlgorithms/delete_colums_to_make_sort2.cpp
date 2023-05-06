#include <bits/stdc++.h>
using namespace std;

int minDeletionSize(vector<string> &strs)
{
    int m = strs.size();
    int n = strs[0].size();

    int res = 0;
    vector<bool> flag(n, false);
    for (int j = 0; j < n; ++j)
    {
        if (flag[j])
        {
            continue;
        }
        int temp = res;
        for (int i = 1; i < m; ++i)
        {
            int k = j;
            while (k < n && (strs[i - 1][k] == strs[i][k] ||
                             flag[k]))
            {
                ++k;
            }

            if (k < n && strs[i - 1][k] > strs[i][k])
            {
                flag[k] = true;
                ++res;
                j = -1;
                break;
            }
        }

        if (temp == res)
        {
            return res;
        }
    }

    return res;
}

int main()
{
    vector<string> strs = {"ca", "bb", "ac"};

    cout << minDeletionSize(strs);

    return 0;
}