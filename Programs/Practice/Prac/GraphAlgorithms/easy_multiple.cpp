#include <bits/stdc++.h>
using namespace std;

long long easyMultiple(long long n)
{
    n = n - 1;
    long long a = n / 3;
    long long b = n / 5;
    long long c = n / 15;
    long long ans = 0;
    ans += ((a) * (2 * 3 + (a - 1) * 3)) / 2;
    ans += (b * (2 * 5 + (b - 1) * 5)) / 2;
    ans -= (c * (2 * 15 + (c - 1) * 15)) / 2;

    return ans;
}
int main()
{

    long long n = 10;

    cout << easyMultiple(n) << "\n";

    return 0;
}