#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;
long solve(int i, int b)
{
    return 1l * ((b + 1) / (1 << (i + 1))) * (1 << i) +
           (((b + 1) % (1 << (i + 1))) -
                        (1 << i) <
                    0
                ? 0
                : ((b + 1) % (1 << (i + 1))) - (1 << i));
}
int main()
{

    vector<int> a = {1, 2, 3, 4};

    long ans = 0;

    for (int i = 0; i < 30; i++)
    {
        long cur1 = solve(i, a[1]) - solve(i, a[0] - 1);
        long cur2 = solve(i, a[3]) - solve(i, a[2] - 1);
        long temp = (cur1 * (a[3] - a[2] + 1 - cur2) % mod *
                     (1 << i)) %
                    mod;
        temp = temp + (cur2 * (a[1] - a[0] + 1 - cur1) %
                       mod * (1 << i)) %
                          mod;
        temp %= mod;
        ans = (ans + temp) % mod;
    }

    cout << ans << "\n";
}
