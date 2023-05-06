#include <bits/stdc++.h>
using namespace std;

int maxSumTwoNoOverlap(vector<int> &A, int l, int m)
{
    vector<int> sum;
    int s = 0;
    for (int i = 0; i < A.size(); i++)
    {
        s += A[i];
        sum.push_back(s);
    }
    vector<int> pre(A.size(), 0);
    vector<int> suf(A.size(), 0);

    pre[l - 1] = sum[l - 1];
    for (int i = l; i < A.size(); i++)
    {
        pre[i] = max(pre[i - 1], sum[i] - sum[i - l]);
    }

    suf[A.size() - m] = sum[A.size() - 1] - sum[A.size() - m - 1];
    for (int i = A.size() - m - 1; i > 0; i--)
    {
        suf[i] = max(suf[i + 1], sum[i + m - 1] - sum[i - 1]);
    }
    int ans = 0;
    for (int i = l - 1; i + 1 < A.size(); i++)
    {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    pre.resize(A.size(), 0);
    suf.resize(A.size(), 0);

    swap(l, m);

    pre[l - 1] = sum[l - 1];
    for (int i = l; i < A.size(); i++)
    {
        pre[i] = max(pre[i - 1], sum[i] - sum[i - l]);
    }
    suf[A.size() - m] = sum[A.size() - 1] - sum[A.size() - m - 1];
    for (int i = A.size() - m - 1; i > 0; i--)
    {
        suf[i] = max(suf[i + 1], sum[i + m - 1] - sum[i - 1]);
    }
    for (int i = l - 1; i + 1 < A.size(); i++)
    {
        ans = max(ans, pre[i] + suf[i + 1]);
    }
    return ans;
}

int main()
{
    vector<int> A = {0, 6, 5, 2, 2, 5, 1, 9, 4};
    int L = 1, M = 2;
    cout << maxSumTwoNoOverlap(A, L, M);

    return 0;
}