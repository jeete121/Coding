#include <bits/stdc++.h>
using namespace std;

int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < ages.size(); i++)
        vec.push_back(make_pair(ages[i], scores[i]));

    //sort the array
    sort(vec.begin(), vec.end());
    vector<int> dp(ages.size());
    int ans = 0, n = vec.size();

    //iterate for all the elements of the array
    for (int i = 0; i < n; i++)
    {

        dp[i] = vec[i].second;
        for (int j = 0; j < i; j++)
        {
            if (vec[j].second <= vec[i].second)
            {
                dp[i] = max(dp[i], dp[j] + vec[i].second);
            }
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main()
{
    vector<int> scores = {1, 3, 5, 10, 15};
    vector<int> ages = {1, 2, 3, 4, 5};

    cout << bestTeamScore(scores, ages);

    return 0;
}