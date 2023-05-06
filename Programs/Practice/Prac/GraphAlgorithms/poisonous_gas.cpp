#include <bits/stdc++.h>
using namespace std;

bool power2(long long n)
{
    if (n & 1)
        return false;
    while (n != 1)
    {
        if (n & 1)
            return false;
        n = n / 2;
    }
    return true;
}

bool poisonousGas(long long n, long long a[])
{
    long long x;
    long long res = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] > 0)
            res += a[i];
    }
    if (res == 1)
        return true;
    else if (res == 0)
        return false;
    else
    {
        bool ans = power2(res);
        if (ans == false)
            return false;
        else
            return true;
    }
}
int main()
{
    long long n = 2;

    long long a[n] = {8, -4};

    if (poisonousGas(n, a))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}