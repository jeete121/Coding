#include <bits/stdc++.h>
using namespace std;

long long additionErrors(long long n, long long m)
{
    long long ans = n + m;

    long long ans1 = 0, rem = 1;
    while (n || m)
    {
        long long x = n % 10 + m % 10;
        n = n / 10;
        x = x % 10;
        m = m / 10;
        ans1 += x * rem;
        rem = rem * 10;
    }
    return ans - ans1;
}
int main()
{

    long long n = 5, m = 8;

    cout << additionErrors(n, m) << "\n";
    return 0;
}