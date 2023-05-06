#include <bits/stdc++.h>
using namespace std;

long long cardGame(long long n, long long a[],
                   long long m, long long b[])
{
    long long max1 = 0;
    for (long long j = 0; j < m; j++)
    {
        max1 = max(max1, b[j]);
    }
    long long res = 0;
    max1++;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] < max1)
            res += max1 - a[i];
    }
    return res;
}
int main()
{
    long long n = 3;
    long long a[n] = {1, 3, 10};

    long long m = 2;
    long long b[m] = {3, 4};

    cout << cardGame(n, a, m, b) << "\n";

    return 0;
}