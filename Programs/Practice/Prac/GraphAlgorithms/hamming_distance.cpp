#include <bits/stdc++.h>
using namespace std;

int hammingDistance(int x, int y)
{
    int res = 0;
    while (x || y)
    {
        if ((x % 2 == 0 && y % 2 != 0) ||
            (x % 2 != 0 && y % 2 == 0))
        {
            res++;
        }
        x = x / 2;
        y = y / 2;
    }
    return res;
}

int main()
{
    int x = 1, y = 4;

    cout << hammingDistance(x, y);

    return 0;
}