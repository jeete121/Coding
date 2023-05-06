#include <bits/stdc++.h>
using namespace std;

int jumpOut(int n, int a[])
{
    int res = n;
    int l = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if ((a[i] + i - n) >= 0)
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

    cout << jumpOut(n, a) << "\n";

    return 0;
}