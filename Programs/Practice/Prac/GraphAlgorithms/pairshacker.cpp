#include <bits/stdc++.h>
using namespace std;

bool prime[10001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (long long i = 2; i * i <= 10000; i++)
    {
        if (prime[i])
        {
            for (long long j = i * i; j <= 10000; j += i)
                prime[j] = false;
        }
    }
}

long long pairs(long long l, long long r)
{
    primeInitialize();

    long long ans[10001] = {0};
    for (long long i = 0; i <= 10000; i++)
    {
        if (prime[i])
            ans[i] = ans[i - 1] + 1;
        else
            ans[i] = ans[i - 1];
    }

    long long cnt = 0;
    cnt = ans[r] - ans[l - 1];
    if (l == 1)
        return (r - l - cnt) * cnt;
    else
        return (r - l - cnt + 1) * cnt;
}
int main()
{
    long long l = 5, r = 11;

    cout << pairs(l, r) << "\n";

    return 0;
}