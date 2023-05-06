#include <bits/stdc++.h>
using namespace std;

bool isSubsetSum(vector<int> S, int k, vector<bool> flag, int n)
{
    if (k == 0)
        return true;
    if (n == 0)
        return false;

    if (S[n - 1] > k)
        return isSubsetSum(S, k, flag, n - 1);
    return isSubsetSum(S, k - S[n - 1], flag, n - 1) || isSubsetSum(S, k, flag, n - 1);
}
int main()
{
    vector<int> S = {12, 1, 61, 5, 9, 2};
    int k = 24;
    vector<bool> flag(S.size());
    int n = S.size();
    bool res = isSubsetSum(S, k, flag, n);

    if (res == true)
        cout << "Yes\n";
    if (res == true)
    {
        for (int i = 0; i < flag.size(); i++)
        {
            if (flag[i] == true)
                cout << S[i];
        }
    }
    else
        cout << "No solution\n";

    return 0;
}