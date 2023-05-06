#include <bits/stdc++.h>
using namespace std;

int maxProfit(int n, int a[])
{
    int buy = a[0];
    int max1 = INT_MIN;
    for (int i = 1; i < n - 1; i++)
    {
        if (a[i] < buy)
        {
            buy = a[i];
        }
        else
        {
            max1 = max(a[i] - buy, max1);
        }
    }
    return max1;
}
int main()
{
    int n = 4;

    int a[n] = {2, 100, 150, 120};

    cout << maxProfit(n, a) << "\n";

    return 0;
}