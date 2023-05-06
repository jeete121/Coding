#include <bits/stdc++.h>
using namespace std;

long long oddFrequency(long long n, long long a[])
{
    long long ans = a[0];
    for (long long i = 1; i < n; i++)
        ans = ans ^ a[i];
    return ans;
}
int main()
{
    long long n = 2;

    n = 2 * n + 1;
    long long a[n] = {1, 2, 3, 2, 1};

    cout << oddFrequency(n, a) << "\n";

    return 0;
}