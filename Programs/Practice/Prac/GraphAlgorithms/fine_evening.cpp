#include <bits/stdc++.h>
using namespace std;

int main()
{
    long n = 72;
    long k = 61;
    long t, s, g;
    if (n >= k)
    {
        if ((log10(k) / log10(2)) == (long)(log10(k) / log10(2)))
            t = (long)(log10(k) / log10(2));
        else
            t = (long)(log10(k) / log10(2)) + 1;
        cout << t + 1 << "\n";
    }
    else
    {
        t = k / n;
        if ((log10(n) / log10(2)) == (long)(log10(n) / log10(2)))
            s = (long)(log10(n) / log10(2));
        else
            s = (long)(log10(n) / log10(2)) + 1;
        k = k % n;
        if ((log10(k) / log10(2)) == (long)(log10(k) / log10(2)))
            g = (long)(log10(k) / log10(2));
        else
            g = (long)(log10(k) / log10(2)) + 1;
        cout << t * s + g + t + 1 << "\n";
    }
}
