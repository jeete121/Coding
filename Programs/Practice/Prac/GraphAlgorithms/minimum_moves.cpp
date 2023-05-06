#include <bits/stdc++.h>
using namespace std;

int minMoves(int x, int y)
{
    if (x < 0 || y < 0)
        return -1;
    else if (x == 0 && y != 0)
        return -1;
    else if (y == 0)
        return x;
    else
    {
        if (y > x)
            return -1;
        else
        {
            int res = min(x, y);
            res += x - y;
            return res;
        }
    }
}
int main()
{

    int x = 1, y = 0;

    cout << minMoves(x, y);

    return 0;
}