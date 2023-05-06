#include <bits/stdc++.h>
using namespace std;

bool prime[10001];
void primeInitialize()
{

    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 10000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 10000; j += i)
                prime[j] = false;
        }
    }
}

int stepUP(int x, int y)
{
    int cnt = 0;
    for (int i = x; i <= y; i++)
    {
        if (prime[i] == false)
        {
            cout << i << "\n";
            cnt++;
        }
    }
    return cnt;
}
int main()
{

    int x = 2, y = 10;

    primeInitialize();

    cout << stepUP(x, y) << "\n";

    return 0;
}