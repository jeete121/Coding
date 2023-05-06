#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int a, b, w;
};
Edge arr[1000001];
int parent[1000001];

//comparator used for sorting
bool cmp(Edge a, Edge b)
{
    return a.w < b.w;
}

//function to find the parent
//of the node
int find(int a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}

//function to make union
void union_set(int a, int b)
{
    parent[a] = b;
}
int main()
{

    int n = 4, m = 6;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
    }
    int a, b, w;
    arr[0].a = 1, arr[0].b = 2, arr[0].w = 5;
    arr[1].a = 1, arr[1].b = 3, arr[1].w = 3;
    arr[2].a = 4, arr[2].b = 1, arr[2].w = 6;
    arr[3].a = 2, arr[3].b = 4, arr[3].w = 7;
    arr[4].a = 3, arr[4].b = 2, arr[4].w = 4;
    arr[5].a = 3, arr[5].b = 4, arr[5].w = 5;

    //sort the edges
    sort(arr, arr + m, cmp);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        a = find(arr[i].a);
        b = find(arr[i].b);
        if (a != b)
        {
            ans += arr[i].w;
            union_set(a, b);
        }
    }
    cout << ans << "\n";
    return 0;
}
