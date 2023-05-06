#include <bits/stdc++.h>
using namespace std;
long long fun(long long n)
{
    if (n < 9)
        return n;
    return n % 9 + 10 * fun(n / 9);
}
int main()
{
    long long n = 100;

    cout << fun(n) << "\n";

    return 0;
}