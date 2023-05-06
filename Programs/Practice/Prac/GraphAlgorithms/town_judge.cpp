#include <bits/stdc++.h>
using namespace std;

int findJudge(int N, vector<vector<int>> &trust)
{
    vector<int> indegree(N + 1);
    vector<bool> trusty(N + 1);
    for (vector<int> e : trust)
    {
        int a = e[0];
        int b = e[1];

        //update indegree
        indegree[b]++;
        trusty[a] = true;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!trusty[i] && indegree[i] == N - 1)
            return i;
    }
    return -1;
}

int main()
{
    int N = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    cout << findJudge(N, trust);
    return 0;
}