#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
long long lcm(long long a, long long b)
{
    return (a * b) / gcd(a, b);
}

long long count(long long n, long long a, long long b, long long c)
{
    long long ans = n / a + n / b + n / c;
    long long x1 = n / lcm(a, b);
    long long x2 = n / lcm(b, c);
    long long x3 = n / lcm(a, c);
    long long x4 = n / lcm(a, lcm(b, c));
    ans = ans - x1 - x2 - x3 + x4;
    return ans;
}
int main()
{

    long long n = 15, a = 2, b = 3, c = 5;

    cout << count(n, a, b, c) << "\n";

    return 0;
}