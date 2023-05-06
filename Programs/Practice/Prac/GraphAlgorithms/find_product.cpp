#include <bits/stdc++.h>
using namespace std;

long long findProduct(long long n, long long a[])
{
    long long ans = 1;
    for (long long i = 0; i < n; i++)
    {

        ans = (ans * a[i]) % (1000000007);
    }
    return ans;
}
int main()
{
    long long n = 5;
    long long a[n] = {1, 2, 3, 4, 5};

    cout << findProduct(n, a) << "\n";

    return 0;
}