#include <bits/stdc++.h>
using namespace std;

int smallestRangeII(vector<int> &A, int K)
{
    multiset<int> st;
    int n = A.size();
    sort(A.begin(), A.end());
    if (K == 0)
        return A[n - 1] - A[0];
    if (n == 1)
        return 0;
    int ans = A[n - 1] - A[0];
    int max1 = A[n - 1];
    for (int i = 0; i < n; i++)
        st.insert(A[i]);

    for (int i = 0; i < n; i++)
    {
        if (st.find(A[i]) != st.end())
            st.erase(st.find(A[i]));
        A[i] = A[i] + 2 * K;
        st.insert(A[i]);
        auto it = st.begin();
        max1 = max(max1, A[i]);
        int min1 = *it;
        ans = min(ans, max1 - min1);
    }
    return ans;
}

int main()
{
    vector<int> A = {1, 3, 6};
    int K = 3;
    cout << smallestRangeII(A, K);
    return 0;
}