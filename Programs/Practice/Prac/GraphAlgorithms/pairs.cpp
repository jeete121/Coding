#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n = 5, k = 2;

    long long arr[n] = {1, 5, 3, 4, 2};

    sort(arr, arr + n);
    long long i = 0, j = 1, diff, cnt = 0;
    while (j < n)
    {
        diff = arr[j] - arr[i];
        if (diff == k)
        {
            cnt++;
            j++;
        }
        else if (diff > k)
            i++;
        else if (diff < k)
            j++;
    }
    cout << cnt << "\n";
    return 0;
}
