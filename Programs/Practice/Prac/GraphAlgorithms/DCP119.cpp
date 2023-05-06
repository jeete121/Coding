#include <bits/stdc++.h>
using namespace std;

vector<int> findCoveringInterval(vector<vector<int>> &intervals)
{
    int smallMax = INT_MAX, largeMin = INT_MIN;
    for (int i = 0; i < intervals.size(); i++)
    {
        smallMax = min(smallMax, intervals[i][1]);
        largeMin = max(largeMin, intervals[i][0]);
    }

    vector<int> res;
    res.push_back(smallMax);
    res.push_back(largeMin);
    sort(res.begin(), res.end());

    return res;
}

int main()
{
    vector<vector<int>> intervals = {{0, 3}, {2, 6}, {3, 4}, {6, 9}};

    vector<int> res = findCoveringInterval(intervals);

    cout << "[";
    cout << res[0] << ", " << res[1];
    cout << "]";

    return 0;
}