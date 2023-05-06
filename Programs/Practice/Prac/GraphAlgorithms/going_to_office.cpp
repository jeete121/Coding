#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long d = 13;
    long long oc = 6, of = 7, od = 4;
    long long cs = 4, cb = 2, cm = 1, cd = 2;

    long long cost1 = 0;
    long long cost2 = 0;
    cost1 = oc + (d - of) * od;
    cost2 = cb + d * cd + (d / cs) * cm;
    if (cost1 <= cost2)
        cout << "Online Taxi\n";
    else
        cout << "Classic Taxi\n";
    return 0;
}