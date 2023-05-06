#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5, k = 3;
    int arr[n] = {4, 2, 6, 1, 10};
    int l = 1;
    int ans = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        for (int j = 1; j <= arr[i]; j++)
        {
            if (cnt < k)
            {
                if (j == l)
                    ans++;
                cnt++;
            }
            else
            {
                cnt = 1;
                l++;
                if (l == j)
                    ans++;
            }
            if (j == arr[i])
                l++;
        }
    }
    cout << ans << "\n";
    return 0;
}
