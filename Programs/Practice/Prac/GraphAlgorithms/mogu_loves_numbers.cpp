#include <bits/stdc++.h>
using namespace std;
bool prime[1000001];

void primeInitialize()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (long long i = 2; i * i <= 100000; i++)
    {
        if (prime[i])
        {
            for (long long j = i * i; j <= 100000; j += i)
                prime[j] = false;
        }
    }
}
int main()
{

    primeInitialize();
    long long ans[100001];
    ans[0] = 0;
    ans[1] = 0;
    long long d = 0;
    for (long long i = 1; i <= 100000; i++)
    {
        if (prime[i])
            d++;
        ans[i] = d;
    }

    long long l = 2, r = 3;

    long long cnt = 0;
    long long min1 = min(l, r);
    long long max1 = max(l, r);
    cnt = ans[max1] - ans[min1 - 1];
    cout << cnt << "\n";

    return 0;
}