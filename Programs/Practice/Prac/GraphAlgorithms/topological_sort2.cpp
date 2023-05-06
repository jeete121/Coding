#include <bits/stdc++.h>
using namespace std;
vector<int> arr[100001];
int in[1000001];
vector<int> res;
bool kahn(int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; i++)
    {
        if (in[i] == 0)
            pq.push(i);
    }
    while (!pq.empty())
    {
        int curr = pq.top();
        res.push_back(curr);
        pq.pop();
        for (int node : arr[curr])
        {
            in[node]--;
            if (in[node] == 0)
                pq.push(node);
        }
    }
    if (res.size() == n)
        return true;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        in[b]++;
    }
    if (kahn(n))
    {
        for (int i = 0; i < n; i++)
            cout << res[i] << " ";
        cout << "\n";
    }
    else
    {
        cout << "Sandro fails.\n";
    }
}