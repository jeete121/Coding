#include <bits/stdc++.h>
using namespace std;

int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < arr.size(); i++)
        mp[arr[i]]++;
    vector<pair<int, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back({it->second, it->first});
    sort(v.begin(), v.end());
    int i = 0;
    for (i = 0; i < v.size(); i++)
    {

        if (k > 0)
        {
            if (v[i].first <= k)
                k -= v[i].first;
            else
                break;
        }
        else
            break;
    }
    return v.size() - i;
}

int main()
{
    vector<int> arr = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    cout << findLeastNumOfUniqueInts(arr, k);
    return 0;
}