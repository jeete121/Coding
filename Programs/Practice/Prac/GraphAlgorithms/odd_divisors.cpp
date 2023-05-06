#include <bits/stdc++.h>
using namespace std;

long long oddDivisors(long long n, long long m)
{
    long long ans = 0;
    while (n)
    {

        ans += (((n / 2 + n % 2) % m) * ((n / 2 + n % 2) % m)) % m;
        ans = ans % m;
        n = n / 2;
    }
    return ans % m;
}
int main()
{

    long long n = 110, m = 30;

    cout << oddDivisors(n, m);

    return 0;
}
