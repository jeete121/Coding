#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l = 11, d = 440;

    int ans = (2 * d) / l;
    int x = 2 * d;
    if (x % l == 0)
        cout << ans << "\n";
    else
        cout << ans + 1 << "\n";
    return 0;
}