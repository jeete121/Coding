#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
long long power(long long a, long long b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 0)
        return power((a * a) % MOD, b / 2);
    return (a * power((a * a) % MOD, (b - 1) / 2)) % MOD;
}
int main()
{
    long long a = 2, b = 5;

    cout << power(a, b) << "\n";
    return 0;
}