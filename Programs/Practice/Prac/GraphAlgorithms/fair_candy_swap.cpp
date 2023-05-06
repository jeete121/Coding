#include <bits/stdc++.h>
using namespace std;

vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
{

    set<int> st;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < A.size(); i++)
    {

        sum1 += A[i];
    }
    for (int i = 0; i < B.size(); i++)
    {
        sum2 += B[i];
        st.insert(B[i]);
    }
    int diff = (sum1 - sum2) / 2;

    for (int i = 0; i < A.size(); i++)
    {
        int val = A[i] - diff;
        if (st.find(val) != st.end())
        {
            return {A[i], val};
        }
    }
    return {};
}

int main()
{
    vector<int> A = {1, 1};
    vector<int> B = {2, 2};
    vector<int> res = fairCandySwap(A, B);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }

    return 0;
}