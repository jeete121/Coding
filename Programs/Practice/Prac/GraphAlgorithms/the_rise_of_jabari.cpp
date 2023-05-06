#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long arr[], long long n)
{
    long long ans = arr[0];
    for (long long i = 1; i < n; i++)
    {
        ans = (ans * arr[i]) / (gcd(arr[i], ans));
    }
    return ans;
}

void riseOfJabari(long long n, long long a[])
{
    sort(a, a + n);
    if (a[0] == 0)
        cout << 0 << "\n";
    else
    {
        long long ans = lcm(a, n);
        cout << ans << "\n";
    }
}
int main()
{
    long long n = 3;

    long long a[n] = {1, 1, 1};

    riseOfJabari(n, a);

    return 0;
}