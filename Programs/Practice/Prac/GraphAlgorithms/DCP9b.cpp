#include <bits/stdc++.h>
using namespace std;

int findMaximumNonAdjacentSum(vector<int> &arr)
{
    int first = 0;
    int second = 0;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int new_sum = max(arr[i] + second, first);
        second = first;
        first = new_sum;
    }

    return first;
}

int main()
{
    vector<int> arr = {2, 4, 6, 2, 5};

    cout << findMaximumNonAdjacentSum(arr);

    return 0;
}
//Time Complexity: O(n)
//Space Complexity: O(1)