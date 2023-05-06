#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long power(long long a, long long b)
{
    if (b == 0)
        return 1;
    long long res = power(a, b / 2) % mod;
    if (b & 1)
        return (((a * res) % mod) * res) % mod;
    return (res * res) % mod;
}
int countGoodNumbers(long long n)
{
    long long even = (n + 1) / 2;
    long long odd = n / 2;

    long long res = (power(5, even) % mod * power(4, odd) % mod) % mod;
    return res % mod;
}

int main()
{
    long long n = 1;
    cout << countGoodNumbers(n) << "\n";

    return 0;
}