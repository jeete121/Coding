#include <bits/stdc++.h>
using namespace std;

void nCoordinates(int n, vector<pair<int, int>> &arr)
{
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n; i++)
    {
        int x = arr[i].first, y = arr[i].second;

        mp[{x, y}]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
        cout << it->first.first << " " << it->first.second << " " << it->second << "\n";
}
int main()
{
    int n = 5;

    vector<pair<int, int>> arr = {{1, 1},
                                  {2, 1},
                                  {1, 3},
                                  {1, 1},
                                  {1, 3}};

    nCoordinates(n, arr);

    return 0;
}