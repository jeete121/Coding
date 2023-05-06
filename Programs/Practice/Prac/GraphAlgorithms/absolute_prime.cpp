#include <bits/stdc++.h>
using namespace std;

int digitsum(int a)
{
    int res = 0;
    while (a)
    {
        res += a % 10;
        a = a / 10;
    }
    return res;
}
bool prime[1000001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
                prime[j] = false;
        }
    }
}

int absolutePrime(int n)
{
    n = n - 1;
    int res = 0;
    while (true)
    {
        int x = digitsum(n);
        if (prime[n] && prime[x])
        {
            res = n;
            break;
        }
        if (n > 2)
            n--;
        else if (n <= 2)
            break;
    }
    return res;
}
int main()
{

    primeInitialize();
    int n = 15;

    cout << absolutePrime(n) << "\n";

    return 0;
}