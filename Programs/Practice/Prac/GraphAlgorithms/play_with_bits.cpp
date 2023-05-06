#include <bits/stdc++.h>
using namespace std;

long long playBits(long long n)
{
    long long res = 0;
    long long x = log2(n) + 1;
    while (n)
    {
        res++;
        n = n & (n - 1);
    }

    return x - res;
}
int main()
{
    long long n = 3;
    long long a[n] = {4, 2, 3};

    long long ans = 0;
    for (long long i = 0; i < n; i++)
        ans += playBits(a[i]);
    cout << ans << "\n";
    return 0;
}