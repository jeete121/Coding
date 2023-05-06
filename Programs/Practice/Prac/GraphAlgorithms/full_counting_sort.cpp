#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, pair<int, string>> a, 
    pair<int, pair<int, string>> b)
{
    if (a.first == b.first)
    {
        return a.second.first < b.second.first;
    }
    return a.first < b.first;
}

void countSort(vector<vector<string>> arr)
{

    int n = arr.size();
    int mid = n / 2;
    vector<pair<int, pair<int, string>>> res;
    for (int i = 0; i < arr.size(); i++)
    {
        string x = arr[i][0];
        string y = arr[i][1];
        if (i < mid)
        {
            res.push_back({stoi(x), {i, "-"}});
        }
        else
            res.push_back({stoi(x), {i, y}});
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < res.size(); i++)
    {

        cout << res[i].second.second << " ";
    }
}

int main()
{
    int n = 6;

    vector<vector<string>> arr = {{"0", "ab"}, {"6", "cd"}, {"0", "ef"}, 
                                {"6", "gh"}, {"4", "ij"}, {"0", "ab"}};
    countSort(arr);

    return 0;
}