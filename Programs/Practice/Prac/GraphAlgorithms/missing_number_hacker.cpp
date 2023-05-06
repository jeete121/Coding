#include <bits/stdc++.h>
using namespace std;

long long missingNumbers(long long n, long long a[])
{
    sort(a, a + n);
    long long res = 2;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] >= res)
            res += 2;
    }
    return res;
}
int main()
{
    long long n = 6;

    long long a[n] = {1, 3, 3, 3, 6, 7};

    cout << missingNumbers(n, a) << "\n";

    return 0;
}