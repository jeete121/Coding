#include <bits/stdc++.h>
using namespace std;

int hackerlandRadioTransmitters(vector<int> arr, int k)
{

    //sort the array
    sort(arr.begin(), arr.end());
    int prev = arr[0];
    int ind = 0;
    int i = 1;
    int cnt = 0;
    int n = arr.size();
    while (i < n)
    {
        while (i < n && arr[i] - arr[ind] <= k)
            i++;
        ind = i - 1;
        while (i < n && arr[i] - arr[ind] <= k)
            i++;
        ind = i;
        cnt++;
    }
    if (cnt == 0)
        return 1;
    else
        return cnt;
}

int main()
{
    int n = 5, k = 1;
    vector<int> arr = {1, 2, 3, 4, 5};

    cout << hackerlandRadioTransmitters(arr, k);
    return 0;
}
