#include <bits/stdc++.h>
using namespace std;

long long strangeGame(long long n, long long k,
                      long long a[], long long b[])
{

    long long max1 = INT_MIN;
    for (long long j = 0; j < n; j++)
    {
        max1 = max(max1, b[j]);
    }

    max1 = max1 + 1;
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] < max1)
        {
            res += (max1 - a[i]) * k;
        }
    }
    return res;
}
int main()
{

    long long n = 5, k = 3;

    long long a[n] = {8, 9, 10, 23, 4};
    long long b[n] = {7, 9, 2, 3, 13};

    cout << strangeGame(n, k, a, b) << "\n";

    return 0;
}