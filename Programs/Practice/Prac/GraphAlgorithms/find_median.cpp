#include <bits/stdc++.h>
using namespace std;

int findMedian(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return arr[n / 2];
}

int main()
{
    int n = 7;

    vector<int> arr = {0, 1, 2, 4, 6, 5, 3};
    int result = findMedian(arr);

    cout << result << "\n";

    return 0;
}
