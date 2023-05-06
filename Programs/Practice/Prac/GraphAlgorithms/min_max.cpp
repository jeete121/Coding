#include <bits/stdc++.h>
using namespace std;

void minMax(long long n, long long a[])
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
    }
    sort(a, a + n);
    long long min1 = sum - a[n - 1];
    long long max1 = sum - a[0];
    cout << min1 << " " << max1 << "\n";
}
int main()
{
    long long n = 5;

    long long a[n] = {1, 2, 3, 4, 5};

    minMax(n, a);

    return 0;
}