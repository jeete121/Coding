#include <bits/stdc++.h>
using namespace std;

long long minAndXorOr(long long n, vector<long long> &a)
{

    sort(a.begin(), a.end());
    long long ans = INT_MAX;
    for (long long i = 0; i < n - 1; i++)
    {
        ans = min(ans, a[i] ^ a[i + 1]);
    }
    return ans;
}
int main()
{

    long long n = 3;
    vector<long long> a = {2, 4, 7};

    cout << minAndXorOr(n, a);

    return 0;
}