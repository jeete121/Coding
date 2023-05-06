#include <bits/stdc++.h>
using namespace std;

long long markTheAnswer(long long n, long long x,
                        long long a[])
{
    long long cnt = 0, skip = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= x && skip <= 1)
            cnt++;
        else
        {
            skip++;
        }
    }
    return cnt;
}
int main()
{
    long long n = 7, x = 6;

    long long a[n] = {4, 3, 7, 6, 7, 2, 2};

    cout << markTheAnswer(n, x, a) << "\n";

    return 0;
}