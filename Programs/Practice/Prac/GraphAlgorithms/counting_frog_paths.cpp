#include <bits/stdc++.h>
using namespace std;

int countFrogPaths(int x, int y, int s, int t)
{
    int sum = 0;
    for (int i = x; i <= x + s; i++)
    {
        for (int j = y; j <= s + y; j++)
        {
            if (i + j <= t)
                sum++;
        }
    }
    return sum;
}
int main()
{

    int x = 2, y = 2, s = 3, t = 6;

    cout << countFrogPaths(x, y, s, t) << "\n";

    return 0;
}