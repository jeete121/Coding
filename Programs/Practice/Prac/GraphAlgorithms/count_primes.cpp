#include <bits/stdc++.h>
using namespace std;

int countPrimes(int n)
{
    bool isprime[n + 1];
    if (n <= 1)
        return 0;
    memset(isprime, true, sizeof(isprime));
    for (int i = 2; i * i < n; i++)
    {
        if (isprime[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = false;
        }
    }
    int cnt = 0;
    for (int i = 2; i < n; i++)
        if (isprime[i])
            cnt++;
    return cnt;
}

int main()
{
    int n = 10;
    cout << countPrimes(n);

    return 0;
}