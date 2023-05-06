#include <bits/stdc++.h>
using namespace std;

void topContestants(long long n, long long k, long long arr[])
{
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++)
        v.push_back({arr[i], i + 1});
    sort(v.begin(), v.end());
    long long cnt = 0;
    for (long long i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i].second << " ";
        cnt++;
        if (cnt == k)
            break;
    }
}
int main()
{
    long long n = 5, k = 3;
    long long arr[n] = {25, 5, 17, 10, 45};

    topContestants(n, k, arr);

    return 0;
}