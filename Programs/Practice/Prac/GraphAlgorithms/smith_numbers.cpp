#include <bits/stdc++.h>
using namespace std;

long long prime[100001];
long long digitSum(long long n)
{
    long long res = 0;
    while (n)
    {
        res += n % 10;
        n = n / 10;
    }
    return res;
}

void primeInitialize()
{

    memset(prime, 0, sizeof(prime));
    for (long long i = 2; i * i <= 100000; i++)
    {
        if (prime[i] == 0)
        {
            for (long long j = i * i; j <= 100000; j += i)
            {
                if (prime[j] == 0)
                    prime[j] = i;
            }
        }
    }
    for (long long i = 2; i <= 100000; i++)
    {
        if (prime[i] == 0)
            prime[i] = i;
    }
}
long long factorize(long long n)
{
    long long sum = 0;
    vector<long long> res;
    while (n != 1)
    {
        res.push_back(prime[n]);
        sum += digitSum(prime[n]);
        n /= prime[n];
    }
    return sum;
}
int main()
{

    primeInitialize();
    long long arr[100001];
    arr[0] = 0;
    arr[1] = 0;
    for (long long i = 2; i <= 100000; i++)
    {
        if (factorize(i) == digitSum(i))
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1];
    }

    long long l = 2, r = 10;

    long long cnt = 0;
    cnt = arr[r] - arr[l - 1];
    cout << cnt << "\n";

    return 0;
}