#include <bits/stdc++.h>
using namespace std;
int parent[1000001];
int size1[1000001];
void make_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        size1[i] = 1;
    }
}
int find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}
void merge_set(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        if (size1[a] < size1[b])
            swap(a, b);
        parent[b] = a;
        size1[a] += size1[b];
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    make_set(n);
    while (q--)
    {
        char c;
        int i, j;
        cin >> c >> i;
        if (c == 'Q')
        {
            int x = find(parent[i]);
            cout << size1[x] << "\n";
        }
        else
        {
            cin >> j;
            merge_set(i, j);
        }
    }
    return 0;
}
