#include <bits/stdc++.h>
using namespace std;

bool prime[10000001];
void primeInitialize()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (long long i = 2; i * i <= 10000000; i++)
    {
        if (prime[i])
        {
            for (long long j = i * i; j <= 10000000; j += i)
                prime[j] = false;
        }
    }
}

long long anotherPrime(long long n)
{
    long long ans = n;
    while (n % 11 != 1)
        n++;
    for (long long i = n;; i += 11)
    {
        if (i % 11 == 1 && prime[i])
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    primeInitialize();
    long long n = 32;

    cout << anotherPrime(n) << "\n";

    return 0;
}