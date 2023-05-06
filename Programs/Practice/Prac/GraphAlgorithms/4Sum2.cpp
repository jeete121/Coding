#include <bits/stdc++.h>
using namespace std;

int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
{
    int n = A.size();
    if (n == 0)
        return 0;
    int sum = 0;
    unordered_map<int, int> mp1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = A[i] + B[j];
            mp1[x]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mp1.find(sum - (C[i] + D[j])) != mp1.end())
                ans += mp1[-(C[i] + D[j])];
        }
    }
    return ans;
}
int main()
{
    vector<int> A = {1, 2};
    vector<int> B = {-2, -1};
    vector<int> C = {-1, 2};
    vector<int> D = {0, 2};
    cout << fourSumCount(A, B, C, D);
    return 0;
}