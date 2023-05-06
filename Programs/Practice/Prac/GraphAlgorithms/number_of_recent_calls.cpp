#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    queue<int> q;
    RecentCounter()
    {
    }
    int ping(int t)
    {
        q.push(t);
        while (!q.empty() && q.front() < (t - 3000) ||
               q.front() > t)
            q.pop();
        return q.size();
    }
};

int main()
{
    RecentCounter recentCounter;

    cout << "[";
    cout << recentCounter.ping(1) << ", ";
    cout << recentCounter.ping(100) << ", ";
    cout << recentCounter.ping(3001) << ", ";
    cout << recentCounter.ping(3002);

    cout << "]";

    return 0;
}