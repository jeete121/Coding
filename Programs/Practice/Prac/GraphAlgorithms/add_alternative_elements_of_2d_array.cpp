#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long a00 = 1, a10 = 2, a20 = 3;
    long long a01 = 4, a11 = 5, a21 = 6, a02 = 7;
    long long a12 = 8, a22 = 9;
    long long ans1 = 0;
    long long ans2 = 0;
    ans1 = a00 + a02 + a11 + a20 + a22;
    ans2 = a01 + a10 + a12 + a21;
    cout << ans1 << "\n"
         << ans2 << "\n";
    return 0;
}