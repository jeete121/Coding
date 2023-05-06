#include <bits/stdc++.h>
using namespace std;

int longestMountain(vector<int> &A)
{
    int up = 0, down = 0;
    int n = A.size();
    if (A.size() < 3)
        return 0;
    int i = 1;
    int ans = INT_MIN;
    while (i < n)
    {
        up = 0;
        while (i < n && A[i - 1] < A[i])
        {
            i++;
            up++;
        }
        down = 0;
        while (i < n && A[i - 1] > A[i])
        {
            i++;
            down++;
        }
        if (i < n && A[i - 1] == A[i])
            i++;
        if (up > 0 && down > 0)
            ans = max(ans, up + down + 1);
    }
    if (ans == INT_MIN)
        return 0;
    return ans;
}

int main()
{
    vector<int> arr = {2, 1, 4, 7, 3, 2, 5};
    cout << longestMountain(arr);
    return 0;
}