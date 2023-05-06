#include <bits/stdc++.h>
using namespace std;

long long oddEvenSubarray(long long a[], long long n)
{
    long long hash_pos[n + 1], hash_neg[n + 1], diff = 0, ans = 0;
    fill_n(hash_pos, n + 1, 0);
    fill_n(hash_neg, n + 1, 0);
    hash_pos[0] = 1;
    for (long long i = 0; i < n; i++)
    {
        if (a[i] & 1 == 1)
            diff++;
        else
            diff--;
        if (diff < 0)
        {
            ans += hash_neg[-diff];
            hash_neg[-diff]++;
        }
        else
        {
            ans += hash_pos[diff];
            hash_pos[diff]++;
        }
    }
    return ans;
}
int main()
{
    long long n = 4;

    long long arr[n] = {1, 2, 1, 2};

    cout << oddEvenSubarray(arr, n) << "\n";

    return 0;
}
