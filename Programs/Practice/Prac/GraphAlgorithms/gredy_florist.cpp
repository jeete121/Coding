#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n = 5, k = 3;
    long long int arr[n] = {1, 3, 5, 7, 9};

    sort(arr, arr + n, greater<long long int>());
    long long int ans = 0;
    long long int l = 0;
    for (long long int i = 0; i < min(k, n); i++)
    {
        ans = (ans + (1 + l) * arr[i]);
    }
    l++;
    int cnt = 0;
    for (long long int i = k; i < n; i++)
    {
        ans = (ans + (1 + l) * arr[i]);
        cnt++;
        if (cnt == k)
        {
            cnt = 0;
            l++;
        }
    }
    cout << ans << "\n";
    return 0;
}
