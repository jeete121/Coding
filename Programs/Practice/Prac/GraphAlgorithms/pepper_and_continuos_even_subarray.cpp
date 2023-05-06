#include <bits/stdc++.h>
using namespace std;

long long continuosEvenSubarray(long long n, long long a[])
{
    long long res = 0, cnt = 0;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] & 1)
        {
            if (cnt > res)
                res = cnt;
            cnt = 0;
        }
        else
        {
            cnt++;
        }
    }
    res = max(cnt, res);
    if (res == 0)
        return -1;
    else
        return res;
}
int main()
{
    long long n = 4;

    long long a[n] = {5, 2, 4, 7};

    cout << continuosEvenSubarray(n, a) << "\n";

    return 0;
}