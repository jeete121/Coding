#include <bits/stdc++.h>
using namespace std;

bool polygonPossibility(long long n, long long a[])
{
    long long sum = 0, max1 = a[0];
    for (long long i = 0; i < n; i++)
    {
        sum += a[i];
        max1 = max(max1, a[i]);
    }
    if (sum - max1 > max1)
        return true;
    else
        return false;
}
int main()
{
    long long n = 3;
    long long a[n] = {4, 3, 2};

    if (polygonPossibility(n, a))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}