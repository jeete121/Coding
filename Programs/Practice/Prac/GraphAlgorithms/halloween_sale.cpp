#include <bits/stdc++.h>
using namespace std;

int howManyGames(int p, int d, int m, int s)
{

    int sum = 0, cnt = 0;
    while (sum < s)
    {
        sum += p;
        if (p - d > m)
            p = p - d;
        else
            p = m;
        if (sum <= s)
            cnt++;
    }
    return cnt;
}

int main()
{
    int p = 20, d = 3;
    int m = 6, s = 80;
    cout << howManyGames(p, d, m, s);
    return 0;
}