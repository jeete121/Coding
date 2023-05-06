#include <bits/stdc++.h>
using namespace std;

long long zrZr(long long n)
{
    long long res = 0;
    for (long long i = 5; n / i > 0; i *= 5)
    {
        res += n / i;
    }
    return res;
}
int main()
{

    long long n = 20;

    cout << zrZr(n) << "\n";

    return 0;
}