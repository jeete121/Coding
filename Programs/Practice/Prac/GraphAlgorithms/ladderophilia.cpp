#include <bits/stdc++.h>
using namespace std;

void ladderOphilia(int n)
{
    int m = n + (n + 1) * 2;
    int l = 2;
    for (int i = 0; i < m; i++)
    {
        if (i == l)
        {
            cout << "*****\n";
            l = l + 3;
        }
        else
            cout << "*   *\n";
    }
}
int main()
{
    int n = 4;

    ladderOphilia(n);

    return 0;
}