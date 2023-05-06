#include <bits/stdc++.h>
using namespace std;

int smallestRangeI(vector<int> &A, int K)
{
    sort(A.begin(), A.end());
    int n = A.size();
    int x = A[n - 1] - A[0];
    cout << x << " "
         << "\n";
    if (x / 2 < K)
        return 0;
    return A[n - 1] - A[0] - 2 * K;
}

int main()
{
    vector<int> A = {0, 10};
    int K = 2;
    cout << smallestRangeI(A, K);
    return 0;
}