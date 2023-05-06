#include <bits/stdc++.h>
using namespace std;

void theGreatKian(long long n, long long a[])
{
    long long arr[n + 1];
    for (long long i = 1; i <= n; i++)
        arr[i] = a[i - 1];
    long long sum1 = 0, sum2 = 0, sum3 = 0;
    for (long long i = 1; i <= n; i += 3)
        sum1 += arr[i];
    for (long long i = 2; i <= n; i += 3)
        sum2 += arr[i];
    for (long long i = 3; i <= n; i += 3)
        sum3 += arr[i];
    cout << sum1 << " " << sum2 << " " << sum3 << "\n";
}
int main()
{
    long long n = 5;

    long long a[] = {1, 2, 3, 4, 5};

    theGreatKian(n, a);

    return 0;
}