#include <bits/stdc++.h>
using namespace std;

long long setBits(long long n)
{
    long long res = 0;
    while (n)
    {
        res++;
        n = n & (n - 1);
    }
    return res;
}
int main()
{
    long long n = 4;

    long long ans = setBits(n);
    if (ans == 1)
        cout << 2 << "\n";
    else
    {
        cout << pow(2, ans) << "\n";
    }

    return 0;
}