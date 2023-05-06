#include <bits/stdc++.h>
using namespace std;

long long maximumCandies(long long n,
                         long long k, long long a[])
{
    priority_queue<long long> q;
    for (long long i = 0; i < n; i++)
    {
        q.push(a[i]);
    }
    long long ans = 0;
    while (!q.empty() && k--)
    {
        ans += q.top();
        long long x = q.top();
        q.pop();
        if (x / 2 > 0)
            q.push(x / 2);
    }
    return ans;
}
int main()
{

    long long n = 5, k = 3;
    long long a[n] = {2, 1, 7, 4, 2};

    cout << maximumCandies(n, k, a) << "\n";

    return 0;
}