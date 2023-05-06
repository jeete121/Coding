#include <bits/stdc++.h>
using namespace std;

string fun(long long n)
{
    string res = "";
    while (n)
    {
        if (n & 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }
    return res;
}
long long coolness(string s)
{
    string pat = "101";
    long long n = s.size();
    if (n < 3)
        return 0;
    long long cnt = 0;
    long long m = 3;
    for (long long i = 0; i <= n - m; i++)
    {
        long long flag = 0;
        for (long long j = 0; j < m; j++)
        {
            if (s[i + j] != pat[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            cnt++;
    }
    return cnt;
}
int main()
{
    long long cool[100001] = {0};
    for (long long i = 1; i <= 100000; i++)
    {
        string x = fun(i);
        cool[i] = coolness(x);
    }

    long long r = 5, k = 1;

    long long ans = 0;
    for (long long i = 1; i <= r; i++)
    {
        if (cool[i] >= k)
            ans++;
    }
    cout << ans << "\n";

    return 0;
}