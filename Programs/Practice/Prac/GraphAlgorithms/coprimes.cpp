#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int coPrimes(int n)
{

    int ans = 1;
    for (int i = n - 2; i > 0; i--)
    {
        if (gcd(n, i) == 1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}
int main()
{
    int n = 4;

    cout << coPrimes(n) << "\n";
    return 0;
}