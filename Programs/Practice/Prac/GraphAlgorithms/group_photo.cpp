#include <bits/stdc++.h>
using namespace std;

void groupPhoto(long long n, long long w[], long long h[])
{
    long long h1[n];
    for (long long i = 0; i < n; i++)
        h1[i] = h[i];
    sort(h1, h1 + n);
    long long max1 = h1[n - 1];
    long long max2 = h1[n - 2];
    long long sum = 0;
    for (long long i = 0; i < n; i++)
        sum += w[i];
    long long res;

    for (long long i = 0; i < n; i++)
    {
        if (h[i] == max1)
        {
            res = max2 * (sum - w[i]);
            cout << res << " ";
        }
        else
        {
            res = max1 * (sum - w[i]);
            cout << res << " ";
        }
    }
}
int main()
{
    long long n = 3;

    long long w[n] = {2, 1, 3}, h[n] = {10, 9, 7};

    groupPhoto(n, w, h);

    return 0;
}