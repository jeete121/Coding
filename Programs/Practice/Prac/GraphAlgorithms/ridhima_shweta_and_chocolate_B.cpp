#include <bits/stdc++.h>
using namespace std;

bool isprime(long long n)
{
    if (n <= 1)
        return false;
    for (long long i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
int main()
{
    long long s = 98562124;
    long long a = s / 2 - 1, b = s / 2 + 1;
    while (true)
    {
        if (isprime(a) && isprime(b))
        {
            break;
        }
        else
        {
            a--;
            b++;
        }
    }
    cout << a << " " << b << "\n";
}