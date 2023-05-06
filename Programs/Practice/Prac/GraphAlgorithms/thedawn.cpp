#include <bits/stdc++.h>
using namespace std;

long long findMinimumSum(long long n)
{
    long long ans;
    long long b, i;
    long long p = sqrt(n);
    for (i = p; i > 0; i--)
    {
        if (n % i == 0)
        {
            b = n / i;
            break;
        }
    }
    ans = i + b;
    return ans;
}
int main()
{
    long long n = 24;

    cout << findMinimumSum(n) << "\n";

    return 0;
}