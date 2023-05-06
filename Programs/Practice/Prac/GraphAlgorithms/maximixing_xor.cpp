#include <bits/stdc++.h>
using namespace std;

int maximizingXor(int l, int r)
{
    int res = 0;
    for (int i = l; i < r; i++)
    {
        for (int j = i + 1; j <= r; j++)
            res = max(i ^ j, res);
    }
    return res;
}

int main()
{
    int l = 10, r = 15;

    cout << maximizingXor(l, r);

    return 0;
}
