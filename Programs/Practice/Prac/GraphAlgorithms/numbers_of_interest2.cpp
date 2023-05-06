#include <bits/stdc++.h>
using namespace std;
int prime(int n)
{
    if (n % 2 == 0)
        return 2;
    for (int i = 3; i * i <= n; i++)
        if (n % i == 0)
            return i;
    return n;
}
int factor(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i != n && n / i == i)
                ans += i;
            else
            {
                if (i != n)
                    ans += i;
                if (n / i != n)
                    ans += n / i;
            }
        }
    }
    return ans;
}
int main()
{

    int arr[100001] = {0};
    for (int i = 2; i <= 100000; i++)
    {
        if (i % 2 == 0)
            arr[i] = 2;
        else
            arr[i] = prime(i);
    }
    int brr[100001] = {0};
    for (int i = 1; i <= 100000; i++)
        brr[i] = factor(i);

    int n = 3;

    int f[n + 1], g[n + 1];
    f[0] = 0;
    int x[n];
    g[0] = 0;
    x[0] = x[1] = 0;
    int y[n];
    y[0] = y[1] = 0;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] + arr[i];
    for (int i = 1; i <= n; i++)
        g[i] = g[i - 1] + brr[i];

    int ans = (f[n] + g[n]) % n;
    cout << ans << "\n";

    return 0;
}