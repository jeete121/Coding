#include <bits/stdc++.h>
using namespace std;

int championLegue(int m, int n, int a[])
{

    priority_queue<int> q;
    for (int i = 0; i < m; i++)
    {
        q.push(a[i]);
    }
    int ans = 0;
    while (!q.empty() && n > 0)
    {
        ans += q.top();
        int x = q.top();
        q.pop();
        if (x > 1)
            q.push(x - 1);
        n--;
    }
    return ans;
}
int main()
{
    int m = 3, n = 4;

    int a[m] = {1, 2, 4};

    cout << championLegue(m, n, a) << "\n";

    return 0;
}