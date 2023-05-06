#include <bits/stdc++.h>
using namespace std;

long long telephoneNetwork(long long n)
{
    long long ans;
    if (n <= 3)
        return 0;
    else
    {
        n = n - 3;
        ans = n * (n + 1) / 2 + n;
        return ans;
    }
}
int main()
{
    long long n = 10;

    cout << telephoneNetwork(n) << "\n";

    return 0;
}