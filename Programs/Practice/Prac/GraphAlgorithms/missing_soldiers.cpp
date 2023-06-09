#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> a;

vector<pair<int, int>> merge(const vector<pair<int, int>> &x)
{
    int n = x.size();

    //if size is 1 then return the
    //same vector
    if (n == 1)
        return x;
    vector<pair<int, int>> res;
    res.push_back(x[0]);
    for (int i = 1; i < n; ++i)
    {
        if (x[i].first <= res.back().second)
        {
            res.back().second = max(res.back().second, x[i].second);
        }
        else
        {
            res.push_back(x[i]);
        }
    }
    return res;
}

int missingSoldiers(int n, vector<vector<int>> &arr)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        a.push_back(make_pair(arr[i][0], arr[i][0] + arr[i][2]));
    }
    //sort the array
    sort(a.begin(), a.end());
    a = merge(a);
    for (int i = 0; i < a.size(); ++i)
    {
        ans += (a[i].second - a[i].first + 1LL);
    }
    return ans;
}
int main()
{

    int n = 2;

    vector<vector<int>> arr = {{1, 1, 4},
                               {7, 3, 5}};

    cout << missingSoldiers(n, arr) << "\n";
    return 0;
}