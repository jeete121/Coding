#include <bits/stdc++.h>
using namespace std;

long long loneInteger(long long n, long long a[])
{
    long long ans = a[0];
    for (long long i = 1; i < n; i++)
    {
        ans = ans ^ a[i];
    }
    if (ans == 0)
        return -1;
    else
        return ans;
}
int main()
{

    long long n = 7;
    long long a[n] = {8, 7, 8, 1, 6, 6, 7};

    cout << loneInteger(n, a) << "\n";

    return 0;
}