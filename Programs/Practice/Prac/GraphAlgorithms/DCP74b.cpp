#include <bits/stdc++.h>
using namespace std;

int findXAppearsinTable(int n, int x)
{
    if (x <= 0 || x > n * n)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (x % i == 0 && x / i <= n)
        {
            ans++;
        }
    }
    return ans;
}
int main()
{

    int n = 6;
    int x = 12;

    cout << findXAppearsinTable(n, x);

    return 0;
}