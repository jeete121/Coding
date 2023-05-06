#include <bits/stdc++.h>
using namespace std;

void maximumSum(long long n, long long a[])
{
    long long sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            sum += a[i];
            cnt++;
        }
    }
    sort(a, a + n);
    if (cnt == 0)
        cout << a[n - 1] << " " << 1 << "\n";
    else
        cout << sum << " " << cnt << "\n";
}
int main()
{
    long long n = 5;

    long long a[n] = {1, 2, -4, -2, 3};

    maximumSum(n, a);

    return 0;
}