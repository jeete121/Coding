#include <bits/stdc++.h>
using namespace std;

bool prime[100000001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (long long i = 2; i * i <= 100000000; i++)
    {
        if (prime[i])
        {
            for (long long j = i * i; j <= 100000000; j += i)
                prime[j] = false;
        }
    }
}

long long primes(long long n)
{

    long long ans = 0, cnt = 0;
    for (long long i = 2;; i++)
    {
        if (prime[i])
        {
            ans += i;
            cnt++;
        }
        if (cnt == n)
            break;
    }
    return ans;
}
int main()
{

    long long n = 10;

    primeInitialize();

    cout << primes(n) << "\n";

    return 0;
}