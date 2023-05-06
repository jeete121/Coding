#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n = 100;
    long long x = 1;
    long long rem, temp = n;
    if (n < 9)
        cout << n << "\n";
    else
    {
        long long ans = 0;
        while (temp >= 9)
        {
            rem = temp % 9;
            ans += rem * x;
            x = x * 10;
            temp = temp / 9;
        }
        ans += temp * x;
        cout << ans << "\n";
    }
}