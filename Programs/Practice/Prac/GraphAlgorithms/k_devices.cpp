#include <bits/stdc++.h>
using namespace std;

long long kDevices(long long n, long long k,
                   long long x[], long long y[])
{
    vector<long long> v;
    for (long long i = 0; i < n; i++)
    {
        long long p = (x[i] * x[i] + y[i] * y[i]);
        double q = sqrt(p);
        q = ceil(q);
        v.push_back(q);
    }
    sort(v.begin(), v.end());

    return v[k - 1];
}
int main()
{
    long long n = 3, k = 3;

    long long x[n] = {1, -1, 1};
    long long y[n] = {1, -1, -1};

    cout << kDevices(n, k, x, y) << "\n";

    return 0;
}