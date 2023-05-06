#include <bits/stdc++.h>
using namespace std;

long long sherlockAndXor(long long n, long long a[])
{
    long long sum[n];
    sum[n - 1] = 0;
    long long odd = 0, even = 0;
    if (a[n - 1] & 1)
        odd = 1;
    else
        even = 1;

    for (long long i = n - 2; i >= 0; i--)
    {
        if (a[i] & 1)
        {
            sum[i] = even;
            odd++;
        }
        else
        {
            sum[i] = odd;
            even++;
        }
    }
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        res += sum[i];
    }
    return res;
}
int main()
{
    long long n = 3;

    long long a[n] = {1, 2, 3};

    cout << sherlockAndXor(n, a) << "\n";

    return 0;
}