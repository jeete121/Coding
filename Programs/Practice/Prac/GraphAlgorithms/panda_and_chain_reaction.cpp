#include <bits/stdc++.h>
using namespace std;
#define MOD 1000003

long long arr[1000004];
void initialize()
{

    arr[0] = 0;
    arr[1] = 1;
    for (long long i = 2; i < 1000004; i++)
        arr[i] = ((arr[i - 1] % MOD) * (i % MOD)) % MOD;
}
long long chainReaction(long long n, long long x)
{
    long long ans;
    if (n >= MOD)
        ans = 0;
    else
        ans = (arr[n] * x) % MOD;
    return ans;
}
int main()
{
    initialize();
    long long n = 1, x = 3;

    cout << chainReaction(n, x) << "\n";

    return 0;
}