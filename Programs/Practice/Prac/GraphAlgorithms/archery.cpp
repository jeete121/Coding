#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long archery(long long n, long long a[])
{
    long long ans = a[0];
    for (long long i = 1; i < n; i++)
    {
        ans = (ans * a[i]) / gcd(a[i], ans);
    }
    return ans;
}
int main()
{
    long long n = 3;

    long long a[n] = {2, 3, 4};

    cout << archery(n, a) << "\n";

    return 0;
}