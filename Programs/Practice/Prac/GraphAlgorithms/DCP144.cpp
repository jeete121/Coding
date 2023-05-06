#include <bits/stdc++.h>
using namespace std;

int findNearestLarger(vector<int> &arr, int index)
{
    int minVal = arr[index], n = arr.size();
    int j = index;
    while (n > (++index) || (--j) >= 0)
    {
        if (index < n && arr[index] > minVal)
        {
            return index;
        }
        if (j >= 0 && arr[j] > minVal)
        {
            return j;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 3, 5, 6};
    int index = 0;

    cout << findNearestLarger(arr, index);

    return 0;
}