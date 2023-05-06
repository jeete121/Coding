#include <bits/stdc++.h>
using namespace std;

int countSetBits(int n)
{
    int cnt = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        cnt++;
    }
    return cnt;
}
int countPrimeSetBits(int L, int R)
{

    bool prime[1000001];
    memset(prime, true, sizeof(prime));
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                prime[j] = false;
            }
        }
    }
    int ans = 0;
    for (int i = L; i <= R; i++)
    {
        int cnt = countSetBits(i);
        if (prime[cnt])
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    int L = 6, R = 10;

    cout << countPrimeSetBits(L, R);

    return 0;
}