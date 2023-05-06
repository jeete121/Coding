#include <bits/stdc++.h>
using namespace std;

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
int nearestPrime(int n)
{

    int res;
    int i = n, j = n;
    while (true)
    {
        if (i > 1 && prime[i])
        {
            res = i;
            break;
        }
        if (prime[j])
        {
            res = j;
            break;
        }
        i--;
        j++;
    }
    return res;
}
int main()
{

    primeInitialize();
    int n = 51;

    cout << nearestPrime(n) << "\n";

    return 0;
}