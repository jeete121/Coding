#include <bits/stdc++.h>
using namespace std;

int minimumJumps(int n, int a[])
{
    int res = n, l = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] + i - n >= 0)
        {
            res = min(res, n - l);
        }
        l++;
    }
    return res;
}
int main()
{
    int n = 5;
    int a[n] = {4, 2, 4, 2, 3};

    cout << minimumJumps(n, a) << "\n";

    return 0;
}