#include <bits/stdc++.h>
using namespace std;

vector<int> dynamicArray(int n, vector<vector<int>> queries)
{
    vector<int> res;
    int lastAnswer = 0;
    vector<vector<int>> v(n, vector<int>());
    int z, x, y;
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {

        z = queries[i][0];
        x = queries[i][1];
        y = queries[i][2];
        if (z == 1)
        {

            int p = (x ^ lastAnswer) % n;
            v[p].push_back(y);
        }
        else if (z == 2)
        {
            int p = (x ^ lastAnswer) % n;
            lastAnswer = v[p][y % v[p].size()];
            res.push_back(lastAnswer);
        }
    }
    return res;
}

int main()
{
    int n = 2, q = 5;
    vector<vector<int>> queries = {{1, 0, 5}, {1, 1, 7}, {1, 0, 3}, {2, 1, 0}, {2, 1, 1}};
    vector<int> res = dynamicArray(n, queries);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << "\n";
    }
    return 0;
}
