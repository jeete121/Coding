#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long power(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return power((a * a) % MOD, b / 2);
    return (a * power((a * a) % MOD, (b - 1) / 2)) % MOD;
}
long long product(long long a[], long long n)
{
    long long res = 1;
    for (long long i = 0; i < n; i++)
        res = (res * a[i]) % MOD;
    return res;
}
long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long FinalCGD(long long a[], long long n)
{
    long long result = a[0];
    for (long long i = 1; i < n; i++)
        result = gcd(a[i], result);
    return result;
}
int main()
{
    long long n = 2;

    long long a[n] = {2, 6};

    long long x = FinalCGD(a, n);
    long long y = product(a, n);

    cout << power(y, x);

    return 0;
}