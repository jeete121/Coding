#include <bits/stdc++.h>
using namespace std;

int monkPowerTime(int n, int calling[], int ideal[])
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(calling[i]);
    }

    int cnt = 0;
    int i = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == ideal[i])
        {

            i++;
            cnt++;
        }
        else
        {
            q.push(x);
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int n = 3;
    int calling[n] = {3, 2, 1};
    int ideal[n] = {1, 3, 2};

    cout << monkPowerTime(n, calling, ideal) << "\n";

    return 0;
}