#include <bits/stdc++.h>
using namespace std;

int maximumSamosa(int n, int k, int a[])
{
    sort(a, a + n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        k = k - a[i];
        if (k >= 0)
            cnt++;
        else
            break;
    }
    return cnt;
}
int main()
{
    int n = 4, k = 10;

    int a[n] = {5, 4, 2, 4};

    cout << maximumSamosa(n, k, a) << "\n";

    return 0;
}