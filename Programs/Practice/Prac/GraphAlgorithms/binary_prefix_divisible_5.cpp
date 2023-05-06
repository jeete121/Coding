#include <bits/stdc++.h>
using namespace std;

vector<bool> prefixesDivBy5(vector<int> &A)
{

    vector<bool> res;
    int sum = 0;
    for (auto a : A)
    {
        sum = (sum * 2 + a) % 5;
        res.push_back(sum == 0);
    }
    return res;
}
int main()
{
    vector<int> A = {0, 1, 1};

    vector<bool> ans = prefixesDivBy5(A);

    cout << "[";
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] == 0)
            cout << "false,";
        else
            cout << "true,";
    }
    if (ans[ans.size() - 1] == 0)
        cout << "false";
    else
        cout << "true";
    cout << "]";

    return 0;
}