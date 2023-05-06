#include <bits/stdc++.h>
using namespace std;

vector<int> numMovesStones(int a, int b, int c)
{
    int x = min(a, min(b, c));
    int z = max(a, max(b, c));
    int y = a + b + c - x - z;

    //if all are consecutive
    if (x + 1 == y && y + 1 == z)
    {
        return {0, 0};
    }

    //if two are consecutive
    if (x + 1 == y)
    {
        return {1, z - y - 1};
    }

    //if two are consecutive
    if (y + 1 == z)
    {
        return {1, y - x - 1};
    }

    //if no two are consecutive
    return {min(2, min(z - y - 1, y - x - 1)), z - x - 2};
}

int main()
{
    int a = 1, b = 2, c = 5;

    vector<int> res = numMovesStones(a, b, c);

    cout << res[0] << " " << res[1] << "\n";

    return 0;
}