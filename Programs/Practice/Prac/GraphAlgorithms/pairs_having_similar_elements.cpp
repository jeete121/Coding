#include <bits/stdc++.h>
using namespace std;

long long pairsHavingSimiElements(long long n, long long a[])
{

    sort(a, a + n);
    long long cnt = 0, ans = 0;
    long long y = 0, i = 0;
    while (i < n)
    {
        if (i < n - 1 && a[i] + 1 == a[i + 1])
        {
            cnt++;
        }
        else if (i < n - 1 && a[i] == a[i + 1])
        {
            cnt++;
            y++;
        }
        else
        {
            if (y != cnt)
                ans += cnt * (cnt + 1) / 2;
            cnt = 0;
            y = 0;
        }
        i++;
    }
    return ans;
}
int main()
{

    long long n = 8;
    long long a[n] = {1, 3, 5, 7, 8, 2, 5, 7};

    cout << pairsHavingSimiElements(n, a) << "\n";

    return 0;
}