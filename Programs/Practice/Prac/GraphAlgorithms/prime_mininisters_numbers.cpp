#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n)
{
    int res = 0;
    while (n)
    {
        res += n % 10;
        n = n / 10;
    }
    return res;
}
bool prime[1000001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000001; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000001; j += i)
                prime[j] = false;
        }
    }
}

void primeMinNumbers(int a, int b)
{
    int cnt = 0;
    for (int i = a; i <= b; i++)
    {
        int sum = sumOfDigits(i);

        if (prime[i] && prime[sum])
            cout << i << " ";
    }
}
int main()
{
    int a = 10, b = 50;

    primeInitialize();

    primeMinNumbers(a, b);

    return 0;
}