#include <bits/stdc++.h>
using namespace std;

vector<string> buildArray(vector<int> &target, int n)
{
    vector<string> res;
    int max1 = target[target.size() - 1];
    for (int i = 1; i <= min(max1, n); i++)
    {
        int j = 0;
        for (j = 0; j < target.size(); j++)
            if (target[j] == i)
            {
                res.push_back("Push");
                break;
            }
        if (j == target.size())
        {
            res.push_back("Push");
            res.push_back("Pop");
        }
    }
    return res;
}

int main()
{
    vector<int> target = {1, 3};
    int n = 3;

    vector<string> res = buildArray(target, n);

    cout << "[";
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i];
        if (i != res.size() - 1)
            cout << ", ";
    }
    cout << "]";

    return 0;
}