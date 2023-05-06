#include <bits/stdc++.h>
using namespace std;

void winTheGame(int r, int g)
{

    if (r == 0)
        cout << 1.000000 << "\n";
    else
    {

        double c = 1.0, ans = 0.0, n = r + g;
        while (r > 0 && g >= 0 && n > 0)
        {
            ans += c * r / n;
            c *= (g) * (g - 1) / ((n - 1) * n);
            g = g - 2;
            n = n - 2;
        }
        cout << fixed << setprecision(6) << ans << "\n";
    }
}
int main()
{

    int r = 2, g = 1;

    winTheGame(r, g);
    return 0;
}