#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int> &arr)
{
    int freq[501] = {0};
    for (int i = 0; i < arr.size(); i++)
        freq[arr[i]]++;
    int res = -1;
    for (int i = 1; i < 501; i++)
        if (freq[i] == i)
        {
            res = max(res, i);
        }
    return res;
}

int main()
{
    vector<int> arr = {2, 2, 3, 4};
    cout << findLucky(arr);
    return 0;
}