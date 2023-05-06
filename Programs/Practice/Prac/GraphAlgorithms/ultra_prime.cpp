#include <bits/stdc++.h>
using namespace std;

long long digit_sum(long long n)
{
    long long res = 0;
    while (n)
    {
        res += n % 10;
        n = n / 10;
    }
    return res;
}

int ultraPrime(int l, int r)
{
    bool prime[10001];
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
    long long sum[10001] = {0};
    for (long long i = 1; i <= 10000; i++)
        sum[i] = digit_sum(i);
    int arr[10001];
    arr[0] = 0;
    for (int i = 1; i <= 10000; i++)
    {
        if (prime[i] && prime[sum[i]])
            arr[i] = arr[i - 1] + 1;
        else
            arr[i] = arr[i - 1];
    }
    int cnt = 0;
    cnt = arr[r] - arr[l - 1];
    return cnt;
}
int main()
{

    long long l = 1, r = 10;

    cout << ultraPrime(l, r) << "\n";

    return 0;
}