#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &A)
{
    int max_sum = A[0];
    int sum = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        // if sum becomes zero or negative then
        // make it as 0
        if (sum <= 0)
            sum = 0;
        // add current element into sum
        sum += A[i];

        // update the max_sum
        max_sum = max(sum, max_sum);
    }
    // return the max sum
    return max_sum;
}
int maxSubarraySumCircular(vector<int> &A)
{
    if (A.size() == 0)
        return 0;
    int y = kadane(A);
    int x = 0;
    for (int i = 0; i < A.size(); i++)
    {
        x += A[i];
        A[i] = -A[i];
    }
    x = x + kadane(A);
    if (x == 0 && y < 0)
        return y;
    return max(y, x);
}

int main()
{
    vector<int> nums = {1, -2, 3, -2};
    cout << maxSubarraySumCircular(nums);
    return 0;
}