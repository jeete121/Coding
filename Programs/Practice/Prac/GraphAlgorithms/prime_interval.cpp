#include <bits/stdc++.h>
using namespace std;

bool isprime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

void primeInterval(int l, int r)
{
    for (int i = l; i <= r; i++)
    {
        if (isprime(i))
        {
            cout << i << " ";
        }
    }
    cout << "\n";
}
int main()
{
    int l = 2, r = 10;

    primeInterval(l, r);

    return 0;
}