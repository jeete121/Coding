#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int killcodeWish(int n, int m, int a[])
{

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        q.push({a[i], i + 1});
    while (q.size() > 1)
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        x = x - m;
        if (x > 0)
            q.push({x, p.second});
    }
    pair<int, int> p1 = q.front();
    return p1.second;
}
int main()
{
    int n = 5, m = 2;

    int a[n] = {1, 3, 1, 4, 2};

    cout << killcodeWish(n, m, a) << "\n";

    return 0;
}