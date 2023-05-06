#include <bits/stdc++.h>
using namespace std;

void frequencyOfStudent(int n, vector<string> &arr)
{
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string s = arr[i];

        mp[s]++;
    }
    vector<pair<string, int>> v;
    for (auto it = mp.begin(); it != mp.end(); it++)
        v.push_back({it->first, it->second});
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        cout << v[i].first << " " << v[i].second << "\n";
}
int main()
{
    int n = 5;

    vector<string> arr = {"sumit", "ambuj", "himanshu",
                          "ambuj", "ambuj"};

    frequencyOfStudent(n, arr);

    return 0;
}