#include <bits/stdc++.h>
using namespace std;

int eliminateMaximum(vector<int> &dist, vector<int> &speed)
{
    for (int i = 0; i < dist.size(); i++)
    {
        dist[i] = (dist[i] - 1) / speed[i];
    }
    sort(dist.begin(), dist.end());

    for (int i = 0; i < dist.size(); i++)
    {
        if (i > dist[i])
            return i;
    }
    return dist.size();
}

int main()
{
    vector<int> dist = {1, 3, 4}, speed = {1, 1, 1};

    cout << eliminateMaximum(dist, speed) << "\n";

    return 0;
}