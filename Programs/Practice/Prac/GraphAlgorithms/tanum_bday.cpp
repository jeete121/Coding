#include <bits/stdc++.h>
using namespace std;

long taumBday(long b, long w, long bc, long wc, long z)
{
    if (bc < wc && (wc - bc) > z)
    {
        return b * bc + w * bc + z * w;
    }
    else if (wc < bc && (bc - wc) > z)
    {
        return b * wc + wc * w + z * b;
    }
    return b * bc + w * wc;
}

int main()
{
    int b = 3, w = 6;
    int bc = 9, wc = 1, z = 1;
    cout << taumBday(b, w, bc, wc, z);
    return 0;
}