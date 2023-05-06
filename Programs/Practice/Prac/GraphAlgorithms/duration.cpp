#include <bits/stdc++.h>
using namespace std;

void duration(int hs, int ms, int he, int me)
{
    int h = he - hs;
    int m = me - ms;
    if (m < 0)
    {
        h = h - 1;
        m = m + 60;
    }
    cout << h << " " << m << "\n";
}
int main()
{

    int hs = 1, ms = 44, he = 2, me = 14;

    duration(hs, ms, he, me);

    return 0;
}