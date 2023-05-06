#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int st[1000001];
int constructSTUtil(vector<int> arr, int ss, int se, int si, int X)
{
    if (ss == se)
    {
        st[si] = arr[ss] ^ X;
        return st[si];
    }
    
    int mid = ss + (se - ss) / 2;
    st[si] = constructSTUtil(arr, ss, mid, si * 2, X) ^
             constructSTUtil(arr, mid + 1, se, si * 2 + 1, X);
    return st[si];
}
int getXorUtil(int ss, int se, int qs, int qe, int si)
{

    if (qs <= ss && qe >= se)
        return st[si];

    if (se < qs || ss > qe)
        return 0;

    int mid = ss + (se - ss) / 2;
    return getXorUtil(ss, mid, qs, qe, 2 * si) ^
           getXorUtil(mid + 1, se, qs, qe, 2 * si + 1);
}
int getXor(int n, int qs, int qe)
{

    if (qs < 0 || qe > n - 1 || qs > qe)
        return 0;
    return getXorUtil(1, n, qs, qe, 0);
}
int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int q;
    cin >> q;
    vector<int> X(q + 1), L(q + 1), R(q + 1);
    for (int i = 1; i <= q; i++)
        cin >> X[i];
    for (int i = 1; i <= q; i++)
        cin >> L[i];

    for (int i = 1; i <= q; i++)
        cin >> R[i];

    int ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int min1 = INT_MAX;
        int K = 0;

        constructSTUtil(arr, L[i], R[i], 1, X[i]);
        ans += getXor(n, L[i], R[i]) % MOD;
        // for (int j = L[i]; j <= R[i]; j++)
        // {
        //     if ((arr[j] ^ X[i]) < min1)
        //     {
        //         min1 = arr[j] ^ X[i];
        //         K = j;
        //     }
        // }
        // ans += K % MOD;
    }

    cout << ans % MOD << "\n";

    return 0;
}