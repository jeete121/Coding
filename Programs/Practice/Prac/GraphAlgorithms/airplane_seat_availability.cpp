#include <bits/stdc++.h>
using namespace std;

double nthPersonGetsNthSeat(int n)
{
    if (n == 1)
        return 1.0;

    return 0.5;
}

int main()
{
    int n = 2;

    cout << nthPersonGetsNthSeat(n);

    return 0;
}