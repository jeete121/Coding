#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long modInverse(long long c, long long m)
{
    long long m0 = m;
    long long y = 0, x = 1;
    if (m == 1)
        return 0;
    while (c > 1)
    {
        long long q = c / m;
        long long t = m;
        m = c % m;
        c = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

long long fact[100001];
void initializeFact()
{

    memset(fact, 0, sizeof(fact));
    fact[1] = 1;
    for (int i = 2; i <= 100000; i++)
        fact[i] = ((fact[i - 1] % MOD) * (i % MOD)) % MOD;
}
long long theEasyOne(string s)
{

    long long n = s.size();
    long long f[10] = {0};
    for (long long i = 0; i < n; i++)
        f[s[i] - '0']++;
    long long ans = fact[n];

    for (long long i = 0; i < 10; i++)
    {
        if (f[i] > 1)
            ans = ((ans % MOD) * modInverse(fact[f[i]], MOD)) % MOD;
    }
    return ans % MOD;
}
int main()
{

    string s = "21";
    initializeFact();

    cout << theEasyOne(s) << "\n";
    return 0;
}