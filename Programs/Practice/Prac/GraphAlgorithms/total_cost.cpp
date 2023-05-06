#include <bits/stdc++.h>
using namespace std;

long long totalCost(long long p, long long s, long long t, long long h, long long x)
{

    long long cost = 0, cnt = 0;
    while (s > t)
    {
        cost += p;
        s--;
        cnt++;
        if (cnt == x)
            break;
    }
    if (cnt < x)
        cost += (x - cnt) * h;
    return cost;
}
int main()
{
    long long p = 6000, s = 10, t = 5, h = 6500, x = 7;

    cout << totalCost(p, s, t, h, x) << "\n";

    return 0;
}