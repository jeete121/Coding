#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long dp[100001];
void fact(long long n)
{

    dp[1] = 1;
    for (long long i = 2; i <= 100000; i++)
        dp[i] = (i * dp[i - 1]) % MOD;
}

long long removeElement(long long n, long long arr[])
{
    sort(arr, arr + n);
    long long ans = 0;
    long long j = 0;
    long long k = 1;
    for (long long i = n - 1; i > 0; i--)
    {
        ans = (ans + ((arr[i]) * dp[k]) % MOD) % MOD;
        k++;
    }
    ans = (ans + arr[0] * dp[n]) % MOD;
    return ans % MOD;
}
int main()
{

    fact(100000);

    long long n = 2;

    long long arr[n] = {3, 3};

    cout << removeElement(n, arr) << "\n";

    return 0;
}