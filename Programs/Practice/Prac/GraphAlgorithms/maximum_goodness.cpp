#include <bits/stdc++.h>
using namespace std;

int maximumGoodness(int n, int a[])
{
    int ans = 0, max1 = 0, sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        if (a[i] == 0)
            x = -1;
        else
            x = 1;
        sum += x;
        cnt++;
        if (sum >= max1)
        {
            max1 = sum;
            if (cnt > ans)
                ans = cnt;
        }
        if (sum < 0)
        {
            sum = 0;
            cnt = 0;
        }
    }
    return ans;
}
int main()
{
    int n = 14;

    int a[n] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0};

    cout << maximumGoodness(n, a) << "\n";

    return 0;
}