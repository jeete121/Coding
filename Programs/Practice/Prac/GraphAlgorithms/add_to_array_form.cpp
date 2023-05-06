#include <bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int> &A, int K)
{
    int n = A.size(), carry = 0;
    vector<int> res;
    for (int i = n - 1; i >= 0; i--)
    {
        res.push_back((carry + A[i] + K % 10) % 10);
        carry = (carry + A[i] + K % 10) / 10;
        K = K / 10;
    }
    if (K > 0)
    {
        while (K)
        {
            res.push_back((K % 10 + carry) % 10);
            carry = (carry + K % 10) / 10;
            K = K / 10;
        }
    }
    if (carry > 0)
        res.push_back(carry);
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> A = {1, 2, 0, 0};
    int K = 34;
    vector<int> arr = addToArrayForm(A, K);
    cout << "[";
    for (int i = 0; i < arr.size() - 1; i++)
        cout << arr[i] << ",";
    cout << arr[arr.size() - 1] << "]";
    return 0;
}