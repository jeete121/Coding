#include <bits/stdc++.h>
using namespace std;

int maxSumMinSum(int n, int m, int a[])
{
    sort(a, a + n);
    int x = n - m;
    int cnt = 0;
    int min_sum = 0, max_sum = 0;
    for (int i = 0; i < x; i++)
        min_sum += a[i];
    for (int i = n - 1; i >= 0; i--)
    {
        max_sum += a[i];
        cnt++;
        if (cnt == x)
            break;
    }
    return max_sum - min_sum;
}
int main()
{

    int n = 5, m = 1;

    int a[n] = {1, 2, 3, 4, 5};

    cout << maxSumMinSum(n, m, a) << "\n";

    return 0;
}