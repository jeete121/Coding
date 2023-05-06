#include <bits/stdc++.h>
using namespace std;

int takeOff(int n, int p, int q, int r)
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i % p == 0 && i % q != 0 && i % r != 0)
            cnt++;
        else if (i % p != 0 && i % q == 0 && i % r != 0)
            cnt++;
        else if (i % p != 0 && i % q != 0 && i % r == 0)
            cnt++;
    }
    return cnt;
}
int main()
{

    int n = 10, p = 2, q = 3, r = 4;

    cout << takeOff(n, p, q, r) << "\n";

    return 0;
}