#include <bits/stdc++.h>
using namespace std;

long long cubeChange(long long n)
{
    long long res;
    if (n == 1)
        return 1;
    else
    {
        res = 6 * n * n - 12 * n + 8;
        return res;
    }
}
int main()
{
    long long n = 3;

    cout << cubeChange(n) << "\n";

    return 0;
}