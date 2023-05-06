#include <bits/stdc++.h>
using namespace std;
vector<long long int> arr[1000001];
long long int vis[1000001];
long long int cnt;

//dfs function
void dfs(long long int node)
{

    //mark as visited
    vis[node] = 1;
    cnt++;
    for (long long int child : arr[node])
    {
        if (vis[child] == 0)
            dfs(child);
    }
}
int main()
{
    long long int n = 3, m = 3, cost_road = 1, cost_lib = 2;
    for (long long int i = 1; i <= n; i++)
    {
        vis[i] = 0;
        arr[i].clear();
    }
    arr[1].push_back(2);
    arr[2].push_back(1);

    arr[3].push_back(1);
    arr[1].push_back(3);

    arr[2].push_back(3);
    arr[3].push_back(2);

    if (cost_lib <= cost_road)
        cout << cost_lib * n << "\n";
    else
    {
        long long int ans = 0;
        for (long long int i = 1; i <= n; i++)
        {
            if (vis[i] == 0)
            {
                cnt = 0;
                dfs(i);
                ans = (ans + (cnt - 1) * cost_road + cost_lib);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
