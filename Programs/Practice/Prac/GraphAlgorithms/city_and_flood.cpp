#include <bits/stdc++.h>
using namespace std;
void initialize(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
        arr[i] = i;
}
bool find(int arr[], int a, int b)
{
    if (arr[a] == arr[b])
        return true;
    return false;
}
void unionDs(int arr[], int a, int b, int n)
{
    int temp = arr[a];
    for (int i = 1; i <= n; i++)
        if (arr[i] == temp)
            arr[i] = arr[b];
}

int cityAndFlood(int n, int k, vector<vector<int>> &edges)
{
    int arr[n + 1];

    initialize(arr, n);
    for (int i = 0; i < k; i++)
    {
        int a = edges[i][0], b = edges[i][1];
        if (find(arr, a, b) == false)
            unionDs(arr, a, b, n);
    }
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
        mp[arr[i]]++;
    return mp.size();
}
int main()
{
    int n = 4, k = 2;

    vector<vector<int>> edges = {{1, 2}, {4, 1}};

    cout << cityAndFlood(n, k, edges) << "\n";

    return 0;
}