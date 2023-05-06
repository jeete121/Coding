#include <bits/stdc++.h>
using namespace std;

long long gameOfString(long long n, string s, string t)
{
    map<char, long long> mp;
    for (long long i = 0; i < 26; i++)
        mp[i + 'A'] = i + 1;
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            long long x = mp[s[i]], y = mp[t[i]];

            if (y > x)
            {
                long long z = 13 + x;
                if (z > y)
                    ans += y - x;
                else
                {
                    ans += 1;
                    ans += y - z;
                }
            }
            else
            {
                long long z = x + 13;
                if (z >= 26)
                {
                    z = z % 26;
                    if (z > y)
                        ans += 26 - x + y;
                    else
                    {
                        ans += 1;
                        ans += y - z;
                    }
                }
                else
                {
                    ans += 1;
                    ans += 26 - z + y;
                }
            }
        }
    }
    return ans;
}
int main()
{

    long long n = 4;

    string s = "ABCT", t = "PBDI";

    cout << gameOfString(n, s, t) << "\n";

    return 0;
}