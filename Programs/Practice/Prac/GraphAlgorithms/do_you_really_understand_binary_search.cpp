#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int intercept, int n)
{
    int lb = 0;
    int ub = arr.size() - 1;
    while (lb <= ub)
    {
        int mid = lb + (ub - lb) / 2;
        if (arr[mid] == intercept)
        {
            return mid;
        }
        else if ((arr[mid] < intercept) && (mid == n - 1 || arr[mid + 1] > intercept))
        {
            return mid;
        }
        else if ((arr[mid] > intercept) && (mid == 0 || arr[mid - 1] < intercept))
        {
            return mid - 1;
        }
        else if (arr[mid] > intercept)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {5, 3};

    sort(arr.begin(), arr.end());
    int x = 3;
    int y = 1;
    int intercept = x + y;
    int floor = binarySearch(arr, intercept, arr.size());
    cout << floor + 1 << "\n";

    return 0;
}
