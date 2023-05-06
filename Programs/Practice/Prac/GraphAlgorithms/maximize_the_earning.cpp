#include <bits/stdc++.h>
using namespace std;

long long maximizeEarning(long long n, long long r,
                          long long height[])
{

    long long max1 = height[0];
    long long res = 1;
    for (long long i = 1; i < n; i++)
    {
        if (height[i] > max1)
            res++;
        max1 = max(max1, height[i]);
    }
    return res * r;
}
int main()
{

    long long n = 6, r = 3;

    long long height[n] = {8, 2, 3, 11, 11, 10};

    cout << maximizeEarning(n, r, height) << "\n";

    return 0;
}