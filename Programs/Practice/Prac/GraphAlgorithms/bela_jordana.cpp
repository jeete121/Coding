#include <bits/stdc++.h>
using namespace std;

long long belaJordana(long long n, long long a[])
{
    long long left[n + 1], right[n + 1];
    left[0] = 0;
    right[n] = 0;
    for (long long i = 1; i <= n; i++)
        left[i] = left[i - 1] + a[i - 1];
    for (long long i = n - 1; i >= 0; i--)
        right[i] = right[i + 1] + a[i];
    long long max1 = 0;
    for (long long i = 1; i < n; i++)
        max1 = max(max1, left[i] * right[i]);
    return max1;
}
int main()
{
    long long n = 5;

    long long a[n] = {1, 2, 3, 4, 5};

    cout << belaJordana(n, a) << "\n";

    return 0;
}