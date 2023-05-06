#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int hexadecimal(int l, int r)
{
    int cnt = 0;
    for (int i = l; i <= r; i++)
    {
        int j = i;
        int res = 0;
        while (j)
        {
            res += j % 16;
            j = j / 16;
        }
        if (gcd(i, res) > 1)
            cnt++;
    }
    return cnt;
}
int main()
{

    int l = 5, r = 8;

    cout << hexadecimal(l, r);

    return 0;
}