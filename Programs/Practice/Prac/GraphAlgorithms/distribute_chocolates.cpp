#include <bits/stdc++.h>
using namespace std;

long long distributeChocolates(long long c, long long n)
{

    long long m = c;
    if (c <= n)
        return c;
    else
    {
        long long sum = n * (n + 1) / 2;
        c = c - sum;
        if (c < 0)
            return m;
        else
        {
            long long p = c / n;
            c = c - p * n;
            return c;
        }
    }
}
int main()
{
    long long c = 20, n = 3;

    cout << distributeChocolates(c, n);

    return 0;
}