#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6, i, no_positive = 0;
    int no_negative = 0, no_zeros = 0;
    float frac_pos, frac_neg, frac_zeros;

    int a[n] = {-4, 3, -9, 0, 4, 1};

    for (i = 0; i < n; i++)
    {
        if (a[i] > 0)
            no_positive++;
        if (a[i] < 0)
            no_negative++;
        if (a[i] == 0)
            no_zeros++;
    }
    frac_pos = (float)no_positive / n;
    frac_neg = (float)no_negative / n;
    frac_zeros = (float)no_zeros / n;
    cout << fixed << setprecision(6);
    cout << frac_pos << "\n";
    cout << frac_neg << "\n";
    cout << frac_zeros << "\n";
    return 0;
}
