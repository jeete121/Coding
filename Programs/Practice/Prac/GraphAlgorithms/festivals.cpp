#include <bits/stdc++.h>
using namespace std;

void festivals(long long n, vector<pair<string, long long>> &vec)
{
    string s;
    long long x;

    priority_queue<pair<string, long long>> v;
    for (long long i = 0; i < n; i++)
    {
        s = vec[i].first;
        x = vec[i].second;
        v.push({s, x});
    }

    string res;
    long long max1 = INT_MIN;
    while (!v.empty())
    {
        string x = v.top().first;
        long long y = v.top().second;
        long long ans = y;
        v.pop();
        long long cnt = 1;
        while (!v.empty() && v.top().first == x)
        {
            if (cnt == 3)
                v.pop();
            else
            {
                ans += v.top().second;
                cnt++;
                v.pop();
            }
        }
        if (ans >= max1)
        {
            max1 = ans;
            res = x;
        }
    }
    cout << res << " " << max1 << "\n";
}

int main()
{
    long long n = 3;

    vector<pair<string, long long>> vec = {{"abc", 10},
                                           {"xyz", 15},
                                           {"oop", 8}};

    festivals(n, vec);

    return 0;
}