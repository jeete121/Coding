#include <bits/stdc++.h>
using namespace std;

long long numberOfOccurrences(long long n,
                              long long a[], long long x)
{
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        mp[a[i]]++;
    }

    return mp[x];
}
int main()
{

    long long n = 5;
    long long a[n] = {5, 8, 1, 4, 5};
    long long x = 5;

    cout << numberOfOccurrences(n, a, x) << "\n";

    return 0;
}