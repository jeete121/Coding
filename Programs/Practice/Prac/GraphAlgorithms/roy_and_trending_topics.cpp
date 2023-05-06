#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long, pair<long long, long long>> a,
         pair<long long, pair<long long, long long>> b)
{
    if (a.first == b.first)
        return a.second.second > b.second.second;
    return a.first > b.first;
}

void trendingTopics(long long n,
                    vector<vector<long long>> &arr)
{
    priority_queue<pair<long long, long long>> q;
    vector<pair<long long, pair<long long, long long>>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            long long id = arr[i][j], score = arr[i][j];
            long long Z = arr[i][j], P = arr[i][j];
            long long L = arr[i][j], C = arr[i][j];
            long long new_score = Z * 50 + P * 5 +
                                  10 * L + 20 * C;
            long long change_score = new_score - score;
            v.push_back(make_pair(change_score,
                                  make_pair(new_score, id)));
        }
    }

    sort(v.begin(), v.end(), cmp);

    long long cnt = 0;
    for (long long i = 0; i < v.size(); i++)
    {
        cout << v[i].second.second << " " << v[i].second.first << "\n";
        cnt++;
        if (cnt == 5)
            break;
    }
}
int main()
{

    long long n = 8;

    vector<vector<long long>> arr = {{1003, 100, 4, 0, 0, 0},
                                     {1002, 200, 6, 0, 0, 0},
                                     {1001, 300, 8, 0, 0, 0},
                                     {1004, 100, 3, 0, 0, 0},
                                     {1005, 200, 3, 0, 0, 0},
                                     {1006, 300, 5, 0, 0, 0},
                                     {1007, 100, 3, 0, 0, 0},
                                     {999, 100, 4, 0, 0, 0}};

    trendingTopics(n, arr);

    return 0;
}