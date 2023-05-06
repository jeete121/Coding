#include <bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>> &dominoes)
{
    map<vector<int>, int> mp;
    int cnt = 0;
    for (int i = 0; i < dominoes.size(); i++)
    {
        vector<int> x = dominoes[i];
        sort(x.begin(), x.end());
        if (mp.find(x) != mp.end())
            cnt += mp[x];
        mp[x]++;
    }
    return cnt;
}

int main()
{
    vector<vector<int>> dominoes = {{1, 2}, {2, 1}, {3, 4}, {5, 6}};
    cout << numEquivDominoPairs(dominoes);
    return 0;
}