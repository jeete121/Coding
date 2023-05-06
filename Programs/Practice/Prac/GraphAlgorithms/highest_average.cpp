#include <bits/stdc++.h>
using namespace std;

long long highestAverage(long long n, long long a[], long long k)
{

    sort(a, a + n);
    long long average[n];

    long long sum[n];
    sum[0] = a[0];
    for (long long i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];
    for (long long i = 0; i < n; i++)
        average[i] = sum[i] / (i + 1);

    long long u = lower_bound(average, average + n, k) - average;
    return u;
}
int main()
{

    long long n = 5;

    long long a[n] = {1, 2, 3, 4, 5};
    long long k = 3;
    cout << highestAverage(n, a, k) << "\n";

    return 0;
}