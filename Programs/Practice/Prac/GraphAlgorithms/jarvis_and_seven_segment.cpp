#include <bits/stdc++.h>
using namespace std;

long long sevenSegment(long long n, long long a[])
{
    map<long long, long long> mp;
    mp[0] = 6;
    mp[1] = 2;
    mp[2] = 5;
    mp[3] = 5;
    mp[4] = 4;
    mp[5] = 5;
    mp[6] = 6;
    mp[7] = 3;
    mp[8] = 7;
    mp[9] = 6;
    long long res = INT_MAX, f = a[0];
    for (long long i = 0; i < n; i++)
    {
        long long x = a[i];
        long long ans = 0;
        if (x == 0)
            ans = mp[0];
        else
        {
            while (x)
            {
                ans += mp[x % 10];
                x = x / 10;
            }
        }
        if (ans < res)
        {
            res = ans;
            f = a[i];
        }
    }
    return f;
}
int main()
{

    long long n = 5;
    long long a[n] = {1, 2, 3, 4, 5};

    cout << sevenSegment(n, a) << "\n";

    return 0;
}