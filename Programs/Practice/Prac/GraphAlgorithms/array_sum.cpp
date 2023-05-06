#include <bits/stdc++.h>
using namespace std;

long long arraySum(long long n, long long a[])
{
    long long sum = 0;
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}
int main()
{
    long long n = 5;

    long long a[n] = {1000000001, 1000000002,
                      1000000003, 1000000004, 1000000005};

    cout << arraySum(n, a) << "\n";

    return 0;
}