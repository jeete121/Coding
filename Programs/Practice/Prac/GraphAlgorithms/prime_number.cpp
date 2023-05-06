#include <bits/stdc++.h>
using namespace std;

bool prime[100001];
void primeInitialize()
{
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 100000; j += i)
                prime[j] = false;
        }
    }
}

void primeNumbers(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
            cout << i << " ";
    }
}
int main()
{
    int n = 9;

    primeInitialize();

    primeNumbers(n);

    return 0;
}