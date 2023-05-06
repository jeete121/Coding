#include <bits/stdc++.h>
using namespace std;

int numOfSubarrays(vector<int> &arr, int k, int threshold)
{
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    if ((double)sum / k >= threshold)
        cnt++;
    for (int i = k; i < arr.size(); i++)
    {
        sum -= arr[i - k];
        sum += arr[i];
        if ((double)sum / k >= threshold)
            cnt++;
    }
    return cnt;
}

int main()
{
    vector<int> arr = {2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3, threshold = 4;
    cout << numOfSubarrays(arr, k, threshold);
    return 0;
}