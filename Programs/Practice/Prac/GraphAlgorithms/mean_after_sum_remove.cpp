#include <bits/stdc++.h>
using namespace std;
double trimMean(vector<int> &arr)
{
    int n = arr.size();
    int x = 5 * n / 100;
    double ans = 0;
    sort(arr.begin(), arr.end());
    for (int i = x; i < n - x; i++)
        ans += arr[i];
    return ans / (n - 2 * x);
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                      2, 2, 2, 2, 2, 2, 2, 2, 3};
    cout << trimMean(arr);
    return 0;
}