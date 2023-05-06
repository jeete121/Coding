#include <bits/stdc++.h>
using namespace std;

vector<int> acmICPC(string str[], int n, int m)
{
    vector<int> v;
    int x = n * (n - 1) / 2;
    int res[x];
    for (int i = 0; i < x; i++)
        res[i] = 0;
    int l = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int j = i + 1;
        while (j < n)
        {
            int cnt = 0;
            for (int k = 0; k < m; k++)
            {
                if (str[i][k] == '1' || str[j][k] == '1')
                    cnt++;
            }
            res[l] = cnt;
            l++;
            j++;
        }
    }
    sort(res, res + x);
    int max1 = res[x - 1];
    int p = x - 1;
    int cnt = 0;
    while (p >= 0 && res[p] == max1)
    {
        cnt++;
        p--;
    }
    v.push_back(max1);
    v.push_back(cnt);
    return v;
}
int main()
{
    int n = 4, m = 5;
    string str[n] = {"10101", "11100", "11010", "00101"};
    vector<int> ans = acmICPC(str, n, m);
    cout << ans[0] << "\n"
         << ans[1] << "\n";
    return 0;
}
