#include <bits/stdc++.h>
using namespace std;

long long cricketBalls(long long n, long long a[], long long sum)
{
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
        mp[a[i]]++;
    set<long long> st;
    for (long long i = 0; i < n; i++)
        st.insert(a[i]);
    long long ans = 0;
    for (auto it = st.begin(); it != st.end(); it++)
    {
        long long x = *it, y = sum - *it;
        if (mp[x] > 0 && mp[y] > 0)
        {
            if (x == y)
            {
                long long p = mp[x];
                ans += p * (p - 1) / 2;
            }
            else
            {
                long long p = mp[x], q = mp[y];
                ans += p * q;
            }
            mp[x] = 0;
            mp[y] = 0;
        }
    }
    return ans;
}
int main()
{

    long long n = 5;

    long long a[n] = {1, 2, 3, 4, 3};

    long long sum = 6;

    cout << cricketBalls(n, a, sum) << "\n";

    return 0;
}
