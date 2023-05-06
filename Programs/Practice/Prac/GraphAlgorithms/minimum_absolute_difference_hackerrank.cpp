#include <bits/stdc++.h>
using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int ans = INT_MAX;
    for (int i = 1; i < arr.size(); i++)
        ans = min(ans, arr[i] - arr[i - 1]);
    return ans;
}

int main()
{
    int n = 5;

    vector<int> arr = {1, -3, 71, 68, 17};
    int result = minimumAbsoluteDifference(arr);
    cout << result << "\n";

    return 0;
}
