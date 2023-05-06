#include <bits/stdc++.h>
using namespace std;

vector<int> constructArray(int n, int k)
{
    vector<int> res;
    for (int i = 0; i <= k; ++i)
    {
        if (i == 0)
        {
            res.push_back(1);
        }
        else if (i == 1)
        {
            res.push_back(k + 1);
        }
        else if (i % 2 == 0)
        {
            res.push_back(res[i - 2] + 1);
        }
        else
        {
            res.push_back(res[i - 2] - 1);
        }
    }

    for (int i = k + 1; i < n; ++i)
    {
        res.push_back(i + 1);
    }

    return res;
}

int main()
{
    int n = 3, k = 2;

    vector<int> res = constructArray(n, k);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}