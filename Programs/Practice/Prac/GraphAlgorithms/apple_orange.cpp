#include <bits/stdc++.h>
using namespace std;

int main()
{

    long int s = 7, t = 11, a = 5, b = 15, m = 3, n = 2, i, p = 0, q = 0;
    long int x[m] = {-2, 2, 1}, y[n] = {5, -6};

    if (a < s && a < t && a < b && s < t && s < b && t < b)
    {
        for (i = 0; i < m; i++)
        {
            if (x[i] + a >= s && x[i] + a <= t)
                p++;
        }
        for (i = 0; i < n; i++)
        {
            if (b + y[i] >= s && b + y[i] <= t)
                q++;
        }
    }
    cout << p << "\n"
         << q << "\n";
    return 0;
}
