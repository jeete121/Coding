#include <bits/stdc++.h>
using namespace std;

int theCastleGate(int n)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if ((i ^ j) <= n)
                cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n = 6;

    cout << theCastleGate(n) << "\n";

    return 0;
}