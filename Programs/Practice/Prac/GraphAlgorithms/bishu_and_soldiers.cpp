#include <bits/stdc++.h>
using namespace std;

void bishuAndSoldiers(int n, int a[], int p)
{

    sort(a, a + n);

    int sum[n];
    sum[0] = a[0];
    for (int i = 1; i < n; i++)
        sum[i] = sum[i - 1] + a[i];

    int u = upper_bound(a, a + n, p) - a;
    cout << u << " " << sum[u - 1] << "\n";
}
int main()
{
    int n = 7;
    int a[n] = {1, 2, 3, 4, 5, 6, 7};
    int p = 3;

    bishuAndSoldiers(n, a, p);

    return 0;
}