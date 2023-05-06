#include <bits/stdc++.h>
using namespace std;

long long fittingCircles(long long a, long long b)
{

    if (a > b)
        return a / b;
    else
        return b / a;
}
int main()
{

    long long a = 40, b = 10;

    cout << fittingCircles(a, b) << "\n";

    return 0;
}