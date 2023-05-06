#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 10, k = 4;
    int arr[n] = {1, 2, 3, 4, 10, 20, 30, 40, 100, 200};

    sort(arr, arr + n);
    int min1 = arr[0];
    int max1 = arr[k - 1];
    int ans = max1 - min1;
    for (int i = k; i < n; i++)
    {
        max1 = arr[i];
        min1 = arr[i - k + 1];
        ans = min(max1 - min1, ans);
    }
    cout << ans << "\n";
    return 0;
}
