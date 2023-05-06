#include <bits/stdc++.h>
using namespace std;

int largestPerimeter(vector<int> &A)
{
    int n = A.size();

    sort(A.begin(), A.end());
    int third = n - 1;
    int second = n - 2;
    int first = n - 3;
    int ans = 0;
    while (first >= 0)
    {
        if (A[first] + A[second] > A[third])
        {
            ans = A[first] + A[second] + A[third];
            break;
        }
        else
        {
            first--;
            second--;
            third--;
        }
    }
    return ans;
}
int main()
{
    vector<int> A = {2, 1, 2};

    cout << largestPerimeter(A);

    return 0;
}